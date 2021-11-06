/*
	GraphList class file for Lab 9
    GraphList.h - CSC 1310 
	David Haleman 
	4/19/2020
*/
#include "GraphList.h"
#include "GraphMatrix.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

int main()
{
	void DepthFirstSearch(int, int, GraphMatrix*);
	Stack<int> stack;
	ifstream inFile;
	string filename;
	int numVertices;
	cout << "Enter the name of your file that contains the graph vertices: " << endl;
	getline(cin, filename);
	inFile.open(filename.c_str());
	if(!inFile)
	{
		cout << "Error opening file." << endl;
	}
	inFile >> numVertices;
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');
	GraphMatrix *matrix = new GraphMatrix(numVertices);
	GraphList *graph = new GraphList(numVertices);
	while (!inFile.eof())
	{
		int temp1;
		int temp2;
		inFile >> temp1;
		inFile >> temp2;
		inFile.ignore(numeric_limits<streamsize>::max(), '\n');
		matrix->addEdge(temp1, temp2);
		graph->addEdge(temp1, temp2);
	}
	cout << "Adjacency Matrix:" << endl;
	matrix->printGraph();
	cout << "Adjancency List:" << endl;
	graph->printGraph();
	cout << "Now traversing & printing graph vertices with DFS. " << endl;
	DepthFirstSearch(0, numVertices, matrix);
	inFile.close();
	delete graph;
	delete matrix;
	return 0;  
}
void DepthFirstSearch(int startV, int totalVertices, GraphMatrix *matrix)
{
	int temp;
	bool *visited = new bool[totalVertices];
	for (int i = 0; i < totalVertices; i++)
	{
		visited[i] = false;
	}
	Stack<int> stack;
	stack.push(startV);
	while (!stack.isEmpty())
	{
		 stack.pop(temp);
		if (!visited[temp])
		{
			visited[temp] = true;
			cout << temp << " ";
			for (int i = totalVertices; i >= 0; i--)
			{
				if (matrix->isThereAnEdge(temp, i) == true)
				{
					stack.push(i);
				}
			}
		}
	}
	cout << endl;
	delete visited;

}