#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <iostream>

using namespace std;

class GraphMatrix
{
    private:
        int **vertexMatrix;
        int numVertices;
        int numEdges;

    public:
        GraphMatrix(int v)
        {
            numVertices = v;
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
        ~GraphMatrix()
        {
            for(int i = 0; i < numVertices; i++)
            {
                delete vertexMatrix[i];
            }
            delete [] vertexMatrix;
        }
        void addEdge(int node1, int node2)
        {
            if (vertexMatrix[node1][node2] != 1)
            {
                vertexMatrix[node1][node2] = 1;
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
};

#endif