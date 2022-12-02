# Program 17: Graph-ADT
Graph ADT header files to closely examine these classes and their methods to manipulate graphs. I have chosen my animal crossing world. PowerPoint presentation included.
[Program 17 Graph by Daniel Arlegui.pptx](https://github.com/DArlegui/Graph-ADT/files/10080793/Program.17.Graph.by.Daniel.Arlegui.pptx)

Instructions

Using any kind of editing software, such as PowerPoint or Keynote or Google Slides, imagine and draw a map of something interesting that would be well represented by a graph. Consider the problems we've seen in the book: a graph representing cities connected by airline routes; islands and bridges; a highway system; etc. Your graph must have at least 10 vertices. Be creative. Make your graph clear to understand and interesting. It should be very obvious what your graph is just by looking at it.

This map should be the first slide in a presentation and it should include vertices indicating roads, bridges, paths, etc. For your second slide, remove the map and just have the graph representation in it and don't forget weights. The third and fourth slides are created using the output data from your code in Part One below. The fifth through at least fourteenth are in Part Two, and the last slide is Part Three.

Write a driver program that will demonstrate your graph in three parts:

Part One: Traversal

Create a graphType object of adequate size, at least 50. Call .createGraph() with a filename to create your graph. Then call and output both traversal methods for the graphType object. Make several copies of the actual map that you drew, and mark up your copies showing how each traversal algorithm proceeded to traverse your graph.

Part Two: Shortest Path

Created a weightedGraphType object of size at least 50. Call .createWeightedGraph() with the same filename to create your weighted graph. Determine the shortest paths from vertex 0 to each other vertex. Mark up your graph copy to show these shortest paths to each vertex.

Part Three: Minimum Spanning Tree

Create a msTreeType object to hold your MST. Call .createSpanningGraph() with the same filename. Determine and output your MST. Mark up your graph copy to show your MST.

Your Slides
You should have a minimum of 13 slides in your PowerPoint:

- The map showing what's being connected
- The graph representation of your map, with directed edges and weights
- Two showing the two traversal algorithms
- At least ten showing the minimum path from vertex 0 to each other vertex (you need one slide per vertex in your graph
- The last one shows the minimum spanning tree
