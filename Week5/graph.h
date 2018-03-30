#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <utility>
#include <vector>
#include <map>

class Graph {
 public:
  // Return the number of nodes in the graph
  int num_nodes() const;

  // Add a new node into the graph
  // Return the index of the new node
  int push_node(std::pair<int, int> cord);

  // Add a new edge into the graph
  // Will overwrite old weight of the edge already exists
  void push_edge(int a, int b, float weight);

  // Get the weight of the edge from a, to b
  // Throws if the edge from a to b does not exist
  float get_weight(int a, int b) const;

  // Get the begin const iterator of adjacents of the node
  std::map<int, float>::const_iterator adjacent_cbegin(int node) const;

  // Get the end const iterator of adjacents of the node
  std::map<int, float>::const_iterator adjacent_cend(int node) const;

 private:
  std::vector<std::pair<int, int>> nodes;
  std::vector<std::map<int, float>> adjacent_edges;
};

#endif
