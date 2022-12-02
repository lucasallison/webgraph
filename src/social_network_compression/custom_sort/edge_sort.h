#ifndef __EDGE_SORT_H__
#define __EDGE_SORT_H__

#include <string>
#include <map>
#include <list>


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


public:
    Edge_Sort();

    virtual ~Edge_Sort();

    bool read_edge_list(const std::string &edge_list, const std::string &sorted_list_dest);

    virtual bool sort(const std::string &sorted_list_dest);
};

#endif /* __EDGE_SORT_H__ */