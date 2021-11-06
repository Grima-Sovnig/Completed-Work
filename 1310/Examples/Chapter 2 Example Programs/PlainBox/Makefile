# this is the Makefile for the PlainBox program
# all you have to do is type the word "make" in the command prompt to compile
# or you can type "make clean" to delete all object & executable files

all			:	PlainBox

PlainBox	:	main.o
			g++ -o PlainBox.exe main.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
main.o		:	main.cpp
			g++ -std=c++11 -c main.cpp
			
			