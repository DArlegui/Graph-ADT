
#ifndef H_msTree
#define H_msTree

//***************************************************************
// Author: D.S. Malik
//
// class msTreeType
// This class specifies the operations to find a minimum
// spanning tree in a graph.
//****************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cfloat>
#include "graphType.h"

using namespace std;

class msTreeType: public graphType
{
public:
    void createSpanningGraph(string);
      //Function to create the graph and the weight matrix.
      //Postcondition: The graph using adjacency lists and 
      //    its weight matrix is created.

    void minimumSpanning(int sVertex);
      //Function to create a minimum spanning tree with
      //root as sVertex. 
      // Postcondition: A minimum spanning tree is created.
      //     The weight of the edges is also saved in the array
      //     edgeWeights.

    void printTreeAndWeight();
      //Function to output the edges of the minimum spanning tree
      //and the weight of the minimum spanning tree.
      //Postcondition: The edges of a minimum spanning tree
      //    and their weights are printed.

    msTreeType(int size = 0); 
      //Constructor
      //Postcondition: gSize = 0; maxSize = size;
      //    graph is an array of pointers to linked lists.
      //    weights is a two-dimensional array to store the weights
      //      of the edges.
      //    edges is an array to store the edges of a minimum
      //      spanning tree.
      //    egdeWeights is an array to store the weights of the
      //      edges of a minimum spanning tree.

    ~msTreeType();
      //Destructor
      //The storage occupied by the vertices and the arrays
      //weights, edges, and edgeWeights is deallocated.

protected:
    int source;
    double **weights;
    int *edges;
    double *edgeWeights;
};

/*
 * Input file format, MST graph in Figure 12-14:
7
0 1 2 3 -999
1 0 4 6 -999
2 0 5 6 -999
3 0 4 -999
4 1 3 5 -999
5 2 4 -999
6 2 1 -999

0 1 6 2 5 3 2 -999  edge 0-1 has weight 6, 0-2 wt 5, 0-3 wt 2
1 0 6 4 2 6 4 -999
2 0 5 5 7 6 5 -999
3 0 2 4 8 -999
4 1 2 3 8 5 10 -999
5 2 7 4 10 -999
6 1 4 2 5 -999

 */

void msTreeType::createSpanningGraph(string fn)
{
    ifstream infile(fn);
    if (!infile)
    {
        cout << "Cannot open input file." << endl;
        return;
    }

    int vertex;
    int adjacentVertex;

    infile >> gSize;

    for (int index = 0; index < gSize; index++)
    {
        infile >> vertex;
        infile >> adjacentVertex;

        while (adjacentVertex != -999)
        {
            graph[vertex].insertLast(adjacentVertex);
            infile >> adjacentVertex;
        } //end while
    } //end for

    for (int i = 0; i < gSize; i++)
        for (int j = 0; j < gSize; j++)
            weights[i][j] = DBL_MAX;

    int weight;

    infile >> vertex;
    while (infile)
    {
        infile >> adjacentVertex;
        while (adjacentVertex != -999)
        {
            infile >> weight;
            weights[vertex][adjacentVertex] = weight;
            infile >> adjacentVertex;
        }
        infile >> vertex;
    }

    infile.close();
} //createWeightedGraph

void msTreeType::minimumSpanning(int sVertex)
{
    int startVertex, endVertex;
    double minWeight;

    source = sVertex;

    bool *mstv;
    mstv = new bool[gSize];

    for (int j = 0; j < gSize; j++)
    {
        mstv[j] = false;
        edges[j] = source;
        edgeWeights[j] = weights[source][j];
    }

    mstv[source] = true;
    edgeWeights[source] = 0;

    for (int i = 0; i < gSize - 1; i++)
    {
        minWeight = DBL_MAX;

        for (int j = 0; j < gSize; j++)
            if (mstv[j])
                for (int k = 0; k < gSize; k++)
                    if (!mstv[k] && weights[j][k] < minWeight)
                    {
                        endVertex = k;
                        startVertex = j;
                        minWeight = weights[j][k];
                    }

        mstv[endVertex] = true;
        edges[endVertex] = startVertex;
        edgeWeights[endVertex] = minWeight;
    } //end for
} //end minimumSpanning

void msTreeType::printTreeAndWeight()
{
    double treeWeight = 0;

    cout << "Source Vertex: " << source << endl;
    cout << "Edges    Weight" << endl;

    for (int j = 0; j < gSize; j++)
    {
        if (edges[j] != j)
        {
            treeWeight = treeWeight + edgeWeights[j];
            cout << "("<<edges[j] << ", " << j << ")    "
                 << edgeWeights[j] << endl;
        }
    }

    cout << endl;
    cout << "Minimum spanning tree weight: " 
         << treeWeight << endl;
} //end printTreeAndWeight

    //Constructor
msTreeType::msTreeType(int size)
           :graphType(size)
{
    weights = new double*[size];

    for (int i = 0; i < size; i++)
        weights[i] = new double[size];

    edges  = new int[size];

    edgeWeights = new double[size];
}

    //Destructor
msTreeType::~msTreeType()
{
    for (int i = 0; i < gSize; i++)
       delete [] weights[i];

    delete [] weights;
    delete [] edges;
    delete edgeWeights;
}

#endif
