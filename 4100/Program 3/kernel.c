// Gabriel Snider
#include <stdio.h>
#include <stdint.h>
#include "convert.h"
#include "buddy.h"
#include <limits.h>

// Phase 1 Structs
typedef struct pcb_t   
{
    uint32_t esp;
    uint32_t priority;
    int pid;
    struct pcb_t *next;

}pcb_t;

typedef struct pcbq_t   
{
    pcb_t *head;
    pcb_t *tail;

}pcbq_t;

// Phase 2 Structs
typedef struct idt_entry_t
{
    uint16_t base_low16;
    uint16_t selector;
    uint8_t  always0;
    uint8_t access;
    uint16_t base_hi16;
}__attribute__((packed)) idt_entry_t;

typedef struct idtr
{
    uint16_t limit;
    uint32_t base;
}__attribute__((packed)) idtr;

// Function Prototypes
void k_clearscr();
void k_printstr(char *string, int row, int col);
void print_border(int start_row, int start_col, int end_row, int end_col);
void enqueue(pcbq_t *q, pcb_t *pcb);
void enqueue_priority(pcbq_t *q, pcb_t *pcb); // New Program 4
pcb_t *dequeue(pcbq_t *q);
pcb_t *dequeue_priority(pcbq_t *q); // New Program 4
int create_process(uint32_t code_address, uint32_t priority);
void default_handler();
void p1();
void p2();
void p3();
void go();
void dispatch();
void dispatch_leave();
void lidtr(uint32_t idtr);
void init_idt_entry(idt_entry_t *entry, uint32_t addr_of_handler, uint16_t code_selector, uint8_t access);
void init_idt();
pcbq_t *initialize();
void setup_PIC();
void init_timer_dev(int ms);
void outportb(uint16_t port, uint8_t value);
void idle();

// Global Variables
int pid;
idt_entry_t idt[256];
pcbq_t *queue;
pcb_t *running;
char buffer[20];

int main()   
{
    buddy_init();
    k_clearscr();
    print_border(0,0,24,79);
    k_printstr("Running processes...",1,1);

    // Intialize a queue
    queue = initialize();
    // Phase 2 Call
    init_idt();
    init_timer_dev(50);
    setup_PIC();
    // Create Process 1
    int retval = create_process((uint32_t) p1, 2);
    /*if (retval < 0)   
    {
        default_handler();
    }*/
    // Create Process 2
    retval = create_process((uint32_t) p2, 2);
    /*if (retval < 0)   
    {
        default_handler();
    }*/

    retval = create_process((uint32_t) p3, 3);

    retval = create_process((uint32_t) idle(), 1);

    go();

}

// Clears the screen
void k_clearscr()   
{
    char spaces[80] = "                                                                                ";
    for (int i=0; i <25; i++)   
    {
        k_printstr(spaces,i, 79);
    }
}

// Function to initialize the queues.
pcbq_t *initialize()
{
    pcbq_t *roundrob = (pcbq_t*)kmalloc(sizeof(pcbq_t));

    roundrob->head = NULL;
    roundrob->tail = NULL;
    return roundrob;
}

// Prints the Border
void print_border(int start_row, int start_col, int end_row, int end_col)   
{

    k_printstr("+", start_row, start_col);

    for (int i = start_col+1; i < end_col; i++)   
    {
        k_printstr("-", start_row, i);
    }

    k_printstr("+", start_row, end_col);

    for (int i=start_row+1; i != end_row; i++)   
    {
        k_printstr("|", i, start_col);

        k_printstr("|", i, end_col);
    }

    k_printstr("+", end_row, start_col);

    for (int i = start_col+1; i < end_col; i++)   
    {
        k_printstr("-", end_row, i);
    }
    
    k_printstr("+", end_row, end_col);
}

// Function to create processes
int create_process(uint32_t code_address, uint32_t priority)   
{
    uint32_t *stackptr = kmalloc(sizeof(1024)*1024);
    uint32_t *st = stackptr + 1024;

    /*st -=1;
    *st= go();
    */

    st -=1;
    *st = 0x200;

    st -=1;
    *st = 16;

    st -=1;
    *st = code_address;

    st -=1;
    *st = dispatch_leave;

    //EBP
    st -=1;
    *st = 0;

    //ESP
    st -=1;
    *st = 0;

    //EDI
    st -=1;
    *st = 0;

    //ESI
    st -=1;
    *st = 0;

    //EDX
    st -=1;
    *st = 0;

    //ECX
    st -=1;
    *st = 0;

    //EBX
    st -=1;
    *st = 0;

    //EAX
    st -=1;
    *st = 0;

    pcb_t *temp = (kmalloc(sizeof(pcb_t)));
    temp->esp = st;
    temp->pid = pid;
    //pid += 1;

    enqueue(queue, temp);

    return 0;
}

// Function to add to the queue.
void enqueue(pcbq_t *q, pcb_t *pcb)   
{
    pcb_t *temp = (pcb_t*)kmalloc(sizeof(pcb_t));
    pcb_t *temp2;
    temp = pcb;
    temp->next = NULL;

    if(q->head == NULL)
    {
        q->head = temp;
        q->tail = temp;
    }
    else
    {
        temp2 = q->head;
        if(temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
        q->tail = temp;
    }
}

// Function to remove from the queue.
pcb_t *dequeue(pcbq_t *q)   
{
    pcb_t *temp = q->head;
    pcb_t *temp2 = q->head;
    q->head = q->head->next;
    kfree(temp);
    return(temp2);
}

void enqueue_priority(pcbq_t *q, pcb_t *pcb)
{

}

pcb_t *dequeue_priority(pcbq_t *q)
{

}

void idle()
{
    k_printstr("Process Idle Running...", 24, 0);
    
    
    do
    {
        k_printstr("/", 24,23);
        k_printstr("\/", 24, 23);
    } while (1);
    
}

// Phase 2 Function
void init_idt_entry(idt_entry_t *entry, uint32_t addr_of_handler, uint16_t code_selector, uint8_t access)
{
    entry->base_low16 = addr_of_handler & 0x0000FFFF;
    entry->base_hi16 = (addr_of_handler >> 16) & 0x0000FFFF;
    entry->selector = code_selector;
    entry->always0 = 0;
    entry->access = access;
}

// Phase 2 Function
void init_idt()
{
    for(int b = 0; b < 32; b++)
    {
        init_idt_entry(idt + b, (uint32_t)default_handler, 16, 0x8e);
    }

    init_idt_entry(idt + 32, (uint32_t)dispatch, 16, 0x8e);

    for(int b = 33; b <256; b++)
    {
        init_idt_entry(idt + b, 0, 0, 0);
    }

    struct idtr idtr;
    idtr.limit = sizeof(idt) - 1;
    idtr.base = (uint32_t)idt;
    lidtr((uint32_t)&idtr);
}

// Default Handler to display if there is a error, also re-used in main not just Phase 2 functions.
void default_handler()   
{
    k_printstr("ERROR", 2,1);
    while(1);
}

// Function for Process 1
void p1()   
{
    print_border(10,10,13,35);
    k_printstr("Process  1 running...",11,11);
    int num = 0;
    k_printstr("value: ",12,11);
    int i = 1;
    for(int i=0; i<INT_MAX/1000; i++)
    {
        convert_num(num, buffer);
        k_printstr(buffer,12,18);
        num += 1;

        if (num >= 1000)   
        {
            num = 0;
        }

    }
}

// Function for Process 2
void p2()   
{
    print_border(15,10,18,35);
    k_printstr("Process  2 running...",16,11);
    int num = 0;
    k_printstr("value: ",17,11);
    int i = 1;
    for(int i=0; i<INT_MAX/1000; i++)
    {
        convert_num(num, buffer);
        k_printstr(buffer,12,18);
        num += 1;

        if (num >= 1000)   
        {
            num = 0;
        }

    }
}

void p3()   
{
    print_border(15,10,18,35);
    k_printstr("Process  2 running...",16,11);
    int num = 0;
    k_printstr("value: ",17,11);
    int i = 1;
    for(int i=0; i<INT_MAX/1000; i++)
    {
        convert_num(num, buffer);
        k_printstr(buffer,12,18);
        num += 1;

        if (num >= 1000)   
        {
            num = 0;
        }

    }
}

void setup_PIC() {
    // set up cascading mode:
    outportb(0x20, 0x11); // start 8259 master initialization
    outportb(0xA0, 0x11); // start 8259 slave initialization
    outportb(0x21, 0x20); // set master base interrupt vector (idt 32-38)
    outportb(0xA1, 0x28); // set slave base interrupt vector (idt 39-45)
    // Tell the master that he has a slave:
    outportb(0x21, 0x04); // set cascade ...
    outportb(0xA1, 0x02); // on IRQ2
    // Enabled 8086 mode:
    outportb(0x21, 0x01); // finish 8259 initialization
    outportb(0xA1, 0x01);
    // Reset the IRQ masks
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0);
    // Now, enable the clock IRQ only 
    outportb(0x21, 0xfe); // Turn on the clock IRQ
    outportb(0xA1, 0xff); // Turn off all others
}