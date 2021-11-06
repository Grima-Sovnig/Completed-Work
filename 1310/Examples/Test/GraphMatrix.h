/*
	GraphMatrix for Program 4 
    GraphMatrix.h - CSC 1310 
	David Haleman 
	4/29/2020
*/
#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H
using namespace std;
#include <iostream>

class GraphMatrix
{
    private:
    int **vertexMatrix;
    int numVertices;
    int numEdges;

    public:
    GraphMatrix(int v) //constructor
    {
        numVertices = v;
        numEdges = 0;
        vertexMatrix = 0;
        vertexMatrix = new int*[numVertices];
        for (int rows = 0; rows < numVertices; rows++)
        {
           vertexMatrix[rows] = new int[numVertices];
           for(int columns = 0; columns < numVertices; columns++)
           {
               vertexMatrix[rows][columns] = 0;
           }
        }
        
    }
    ~GraphMatrix()// destructor
    {
        for(int i = 0; i <numVertices; i++)
        {
            delete vertexMatrix[i];
        }
        delete [] vertexMatrix;
    }
    void addEdge(int node1, int node2)
    {
        cout << "adding an edge from " << node1 << " to " << node2 << " in the matrix. " << endl;
        if (vertexMatrix[node1][node2] != 1)
        {
            vertexMatrix[node1][node2] = 1;
        }
        else
        {
            cout << node1 << " already has an edge to " << node2 << " in the matrix. " << endl;
        }

    }
    void printGraph()
    {
        for(int i = 0; i <numVertices; i++)
        {
            for(int j = 0; j < numVertices; j++)
            {
                 cout << vertexMatrix[i][j] << " ";
            }
            cout << endl;
        }
            cout << endl;
    }
    bool isThereAnEdge(int node1, int node2)
    {
        if (vertexMatrix[node1][node2] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};





















#endif