//*****************
//Program Name: Program 17
//Author: Daniel Arlegui
//IDE Used: Eclipse
//Program description: Graph Your Stuff
//*****************

//Libraries
#include <iostream>
#include <fstream>
#include "graphType.h"
#include "weightedGraph.h"
#include "minimumSpanTreeType.h"
using namespace std;

int main(){

	graphType myTown(50);
	myTown.createGraph("myTown.txt");

	cout << "Part 1: Traversals";
	cout << "\nDepth First Traversal: ";
	myTown.depthFirstTraversal();
	cout << "\nBreadth First Traversal: ";
	myTown.breadthFirstTraversal();

	weightedGraphType myTownW(50);
	myTownW.createWeightedGraph("myTown.txt");
	cout << "\n\nPart 2: Shortest Path";
	myTownW.shortestPath(0);
	cout << "\nVertex" << setw(22) << "Shortest_Distance" << endl;
	myTownW.printShortestDistance(0);

	msTreeType myTownT(50);
	myTownT.createSpanningGraph("myTown.txt");
	myTownT.minimumSpanning(0);
	cout << "Part 3: Minimum Spanning Tree" << endl;
	myTownT.printTreeAndWeight();

	cout << "\nThis is my original work; apart from standard tutoring or class collaboration, "
		"\nI neither received help nor copied this code from another source."  << endl;

	return 0;
}
