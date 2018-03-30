#include "mst.h"
#include <queue>

using namespace std;

struct Edge {
  int from;
  int to;
  float weight;
};

bool operator<(const Edge& a, const Edge& b) {
  return a.weight > b.weight;
}

vector<pair<int, int>> PrimMST::computeMST(const Graph& graph) {
  vector<pair<int, int>> result;
  vector<bool> visited_nodes(graph.num_nodes(), false);
  if (graph.num_nodes() > 0) {
    visited_nodes[0] = true;
    priority_queue<Edge> pq;
    int node = 0;
    for (auto it = graph.adjacent_cbegin(node); it != graph.adjacent_cend(node);
         it++) {
      pq.push(Edge{node, it->first, it->second});
    }

    while (!pq.empty()) {
      Edge current = pq.top();
      int from = current.from, to = current.to;
      pq.pop();
      if (visited_nodes[to]) {
        continue;
      }

      visited_nodes[to] = true;
      result.push_back(pair<int, int>(min(from, to), max(from, to)));
      for (auto it = graph.adjacent_cbegin(to); it != graph.adjacent_cend(to);
           it++) {
        if (visited_nodes[it->first]) {
          continue;
        }
        pq.push(Edge{to, it->first, it->second});
      }
    }
  }
  return result;
}

// UnionFind: Find the parent of the node, with path compress
int get_parent(vector<int>& parent, int node) {
  return node == parent[node]
             ? node
             : (parent[node] = get_parent(parent, parent[node]));
}

vector<pair<int, int>> KruskalMST::computeMST(const Graph& graph) {
  vector<pair<int, int>> result;
  priority_queue<Edge> pq;
  // UnionFind
  vector<int> parent(graph.num_nodes(), 0);
  for (int i = 0; i < graph.num_nodes(); i++) {
    parent[i] = i;

    for (auto it = graph.adjacent_cbegin(i); it != graph.adjacent_cend(i);
         it++) {
      pq.push(Edge{i, it->first, it->second});
    }
  }

  while (!pq.empty()) {
    Edge current = pq.top();
    pq.pop();
    int from = current.from, to = current.to;
    int parent_from = get_parent(parent, from);
    int parent_to = get_parent(parent, to);

    if (parent_from != parent_to) {
      result.push_back(pair<int, int>(min(from, to), max(from, to)));
      parent[parent_from] = parent_to;
    }
  }
  return result;
}
