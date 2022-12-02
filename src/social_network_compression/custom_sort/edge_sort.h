#ifndef __EDGE_SORT_H__
#define __EDGE_SORT_H__

#include <string>
#include <map>
#include <list>
#include <vector>

/*
Base class for the sorting algorithm. Manages reading and writing graphs as well as storing them in appropriate formats.
*/
class Edge_Sort
{

protected:
    // Nodes are internally represented by integers
    // With this map the actual node identifier can be retrieved, such as names
    std::map<int, std::string> _node_identifier;
    int _node_count;

    // Sparse representation of the matrix
    int *_col_ind = nullptr;
    int *_row_ptr_begin = nullptr;
    int *_row_ptr_end = nullptr;

    // Return the number of successors these nodes have in common and their respective degrees
    int compare_nodes(const int i, const int j, int *degree_i, int *degree_j);

    bool write_sorted_nodes_to_file(std::list<int> &order, const std::string &sorted_list_dest);

    // Reads in edgelist. Sets the node count and sorts them. This is done in case the edge list provided is not sorted
    bool read_edge_list(const std::string &edge_list, std::vector<std::vector<std::string>> *content, std::map<std::string, int> *node_identifier_to_index);

    

public:
    Edge_Sort();

    virtual ~Edge_Sort();

    bool load_graph(const std::string &edge_list);

    virtual bool sort(const std::string &sorted_list_dest);
};

#endif /* __EDGE_SORT_H__ */