#include <iostream>
#include <fstream>
#include <string>
#include "GraphList.h"

using namespace std;

int main()
{
    ifstream infile;
    string filename;
    int numVertices;

    filename = "graph.txt";

    infile.open(filename.c_str());
    if(!infile)
    {
        cout << "Error! Could not open file." << endl;
    }
    
    infile >> numVertices;

    cout << "There are " << numVertices << " vertices in the graph." << endl;

    GraphList *graph = new GraphList(numVertices);
    while(!infile.eof())
    {
        int temp1;
        int temp2;
        infile >> temp1;
        infile >> temp2;
        graph->addEdge(temp1, temp2);
    }
    cout << "Adjancency List:" << endl;
    graph->printGraph();

    infile.close();

    return 0;
}