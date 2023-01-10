#include <stdio.h>


void k_clearscr();
void k_printstr(char *string, int row, int col);
void print_border(int start_row, int start_col, int end_row, int end_col);


int main()
{
    k_clearscr();
    print_border(0,0,24,79);
    run_test();
    while(1);
}

void k_clearscr()
{   
    // Variable for 80 spaces.
    char spaces[80] = "                                                                                ";
    // Prints the 80 spaces to clear the screen
    for(int i=0; i < 25; i++)
    {
        k_printstr(spaces, i, 79);
    }
}

void print_border(int start_row, int start_col, int end_row, int end_col)
{
    /* These loops print the | and - along the outer borders of the display. */
    for(int i=0; i<end_row; i++)
    {
        k_printstr("|", i, start_col);
        k_printstr("|", i, end_col);

    }
    for (int i = 0; i<end_col; i++)
    {
        k_printstr("-", start_row, i);
        k_printstr("-", end_row, i);
    }
    /* These 4 calls of k_printstr place the + in the corners of the display. */
    k_printstr("+",0,0);
    k_printstr("+",0,79);
    k_printstr("+",24,0);
    k_printstr("+",24,79);
    
}