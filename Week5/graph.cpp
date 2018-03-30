#include "graph.h"

int Graph::num_nodes() const {
  return nodes.size();
}

int Graph::push_node(std::pair<int, int> cord) {
  int len = nodes.size();
  nodes.push_back(cord);
  adjacent_edges.push_back(std::map<int, float>());
  return len;
}

void Graph::push_edge(int a, int b, float weight) {
  adjacent_edges[a][b] = weight;
  adjacent_edges[b][a] = weight;
}

float Graph::get_weight(int a, int b) const {
  return adjacent_edges.at(a).at(b);
}

std::map<int, float>::const_iterator Graph::adjacent_cbegin(int node) const {
  return adjacent_edges[node].cbegin();
}

std::map<int, float>::const_iterator Graph::adjacent_cend(int node) const {
  return adjacent_edges[node].cend();
}
