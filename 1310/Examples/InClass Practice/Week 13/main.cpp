/*
	Title:  main.cpp
	Author:  April Crockett
	Date:  11/15/2020
	Purpose:  To demonstrate graph representation with a matrix
*/
#include <iostream>
#include <fstream>
#include "GraphMatrix.h"

using namespace std;

int main()
{
	int numVerticies;
	int v1, v2;
	ifstream inFile;
	char filename[25];
	
	inFile.open("graph.txt");
	if(!inFile)
	{
		cout << "\n\nSorry.  That file doesn't exist!\n\n";
		exit(1);
	}
	inFile >> numVerticies;
	cout << "\n\nThere are " << numVerticies << " vertices in the graph.\n";
	
	GraphMatrix myGraphMatrix(numVerticies);
	
	
	while(inFile >> v1)
	{
		inFile >> v2;
		cout << "\nAdding an edge from " << v1 << " to " << v2 << ".";
		myGraphMatrix.addEdge(v1, v2);
	}

	cout << "\n\nAdjacency Matrix...\n";
	myGraphMatrix.printGraph();
	
	inFile.close();
	
	return 0;
}