# Custom Sorting Algorithms

This subdirectory contains algorithms which order edge lists based on custom sorting algorithms, which can in turn be used by the webgraph framework to compress them. The program expects an edge list as an input and ouputs a graph in the AsciiGraph file format, as expected by the webgraph framework. It takes an edge list as input because this is commonly used by widely available datasets. It also ouputs a node mapping. It states by which index a node is represented in the sorted AsciiGraph file. This way the original node can be retrieved when inspecting the graph with the webgraph framework. 

## Edge Sort Base Class

The file "edge_sort.h" contains the base class which is called in the main function. The base class can be extended by different child class implementation in order to experiment with different algorithms to sort the edges.

## Similarity Sort

Implementation of edge sort. It sort the nodes based on 'similarity'. It places nodes that have similar successors as close as possible to eachother in the output file. For more info ... reference paper

## TODO's

- Support multiple file formats for reading in graphs
- The node mapping is saved in a seperate file, is this the best solution?
- Smaller TODO's are indicated by comments n the code

