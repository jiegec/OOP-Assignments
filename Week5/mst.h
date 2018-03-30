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

#endif
