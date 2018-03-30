#ifndef __MST_H__
#define __MST_H__

#include "graph.h"
#include <vector>
#include <utility>

class PrimMST {
 public:
  // Calculate the MST from the graph
  // Result is a vector of edges that compose the MST
  // edge.from is smaller than edge.to
  static std::vector<std::pair<int, int>> computeMST(const Graph &graph);
};

class KruskalMST {
 public:
  // Calculate the MST from the graph
  // Result is a vector of edges that compose the MST
  // edge.from is smaller than edge.to
  static std::vector<std::pair<int, int>> computeMST(const Graph &graph);
};

//[1]	Amal P M and Ajish Kumar K S, “An Algorithm for kth Minimum Spanning Tree,” Electronic Notes in Discrete Mathematics, vol. 53, pp. 343–354, Sep. 2016.
class AmalAjishKumarMST {
 public:
  // Calculate the Top KMST from the graph
  // Result is a len-k vector of a vector of edges that compose the MST
  // edge.from is smaller than edge.to
  static std::vector<std::vector<std::pair<int, int>>> computeTopKMST(const Graph &graph, int k);
};

#endif
