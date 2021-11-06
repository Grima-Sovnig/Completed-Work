#this is a comment

all				:	GRAPH

GRAPH			:	graph.o
					g++ -std=c++11 -o graph.exe graph.o

#here is how to generate the .o file
#if any of the files listed has been altered since the last compile, generate a new .o file
graph.o	:			graph.cpp
					g++  -std=c++11 -c graph.cpp

clean			:	graph.exe
					del *.o 
					del graph.exe