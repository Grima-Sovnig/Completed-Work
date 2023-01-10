all: boot1 boot2

boot1: boot1.asm kernel.exe
	nasm -DENTRY=0x00010000 boot1.asm

boot2: kernel.exe
	objcopy -j .text* -j .data* -j .rodata* -S -O binary kernel.exe boot2

kernel_c.o: kernel.c
	gcc -g -m32 -fno-stack-protector -c -o kernel_c.o kernel.c

kernel_asm.o: kernel.asm
	nasm -g -f elf -F dwarf -o kernel_asm.o kernel.asm

buddy_c.o: buddy.c
	gcc -g -m32 -fno-stack-protector -c -o buddy_c.o buddy.c

convert_c.o: convert.c
	gcc -g -m32 -fno-stack-protector -c -o convert_c.o convert.c

kernel.exe: kernel_c.o kernel_asm.o buddy_c.o convert_c.o
	ld -g -melf_i386 -Ttext 0x1000 -e main -o kernel.exe kernel_c.o kernel_asm.o convert_c.o buddy_c.o

clean:
	rm -rf *.o *.exe boot2 boot1 a.img

install:
	dd if=/dev/zero of=a.img bs=512 count=2880 
	/sbin/mkdosfs a.img
	dd if=boot1 of=a.img bs=1 count=512 conv=notrunc
	mcopy -o boot2 a:BOOT2

run:
	qemu-system-i386 -drive format=raw,file=a.img,if=floppy
	
debug:
	qemu-system-i386 -S -s -drive format=raw,file=a.img,if=floppy &
    ddd --debugger 'gdb -ex "target remote localhost:1234" -ex "break main" -ex "continue"' kernel.exe