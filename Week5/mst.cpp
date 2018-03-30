#include "mst.h"
#include <queue>
#include <set>

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

struct MSTWithWeight {
  vector<pair<int, int>> mst;
  float weight;

  MSTWithWeight(const Graph& graph, vector<pair<int, int>> mst) : mst(mst) {
    weight = 0;
    for (auto it = mst.cbegin(); it != mst.cend(); it++) {
      weight += graph.get_weight(it->first, it->second);
    }
  }
};

bool operator<(const MSTWithWeight& a, const MSTWithWeight& b) {
  return a.weight < b.weight;
}

// naive implementation
// find the path from current to target in a tree
// return the length of the path
int dfs_cycle(const vector<pair<int, int>>& mst,
              int current,
              int target,
              vector<pair<int, int>>& path) {
  if (current == target) {
    return 0;
  }
  for (int i = 0; i < mst.size(); i++) {
    if (mst[i].first == current || mst[i].second == current) {
      if (path.size() == 0 ||
          (path.size() > 0 && path[path.size() - 1] != mst[i])) {
        path.push_back(mst[i]);
        int result = dfs_cycle(mst, mst[i].first + mst[i].second - current,
                               target, path);
        if (result != -1) {
          return 1 + result;
        }
        path.pop_back();
      }
    }
  }
  return -1;
}

vector<vector<pair<int, int>>> AmalAjishKumarMST::computeTopKMST(
    const Graph& graph,
    int k) {
  set<vector<pair<int, int>>> result;
  set<MSTWithWeight> list_of_mst;
  auto mst = MSTWithWeight(graph, PrimMST::computeMST(graph));
  result.insert(mst.mst);
  list_of_mst.insert(mst);

  for (int i = 2; result.size() < k; i++) {
    list_of_mst.erase(list_of_mst.begin());

    for (int i = 0; i < graph.num_nodes(); i++) {
      for (auto it = graph.adjacent_cbegin(i); it != graph.adjacent_cend(i);
           it++) {
        // naive implementation.. slow!
        pair<int, int> new_edge(min(i, it->first), max(i, it->first));
        auto new_edge_weight =
            graph.get_weight(new_edge.first, new_edge.second);
        int j;
        for (j = 0; j < mst.mst.size(); j++) {
          if (new_edge == mst.mst[j]) {
            // already jn MST
            break;
          }
        }

        if (j == mst.mst.size()) {
          // edge not in mst
          auto max_weight = 0.0;
          vector<pair<int, int>> cycle_path;
          auto cycle =
              dfs_cycle(mst.mst, new_edge.first, new_edge.second, cycle_path);
          for (int k = 0; k < cycle; k++) {
            auto edge = cycle_path[k];
            auto weight = graph.get_weight(edge.first, edge.second);
            if (weight < new_edge_weight ||
                (weight == new_edge_weight && i == 2)) {
              if (weight > max_weight) {
                max_weight = weight;
              }
            }
          }

          for (int k = 0; k < cycle; k++) {
            auto edge = cycle_path[k];
            auto weight = graph.get_weight(edge.first, edge.second);
            if (weight == max_weight) {
              auto new_mst = mst;
              for (int h = 0; h < mst.mst.size(); h++) {
                if (edge == mst.mst[h]) {
                  new_mst.mst[h] = new_edge;
                  // naive...
                  sort(new_mst.mst.begin(), new_mst.mst.end());
                  new_mst.weight = new_mst.weight - weight + new_edge_weight;
                  list_of_mst.insert(new_mst);
                }
              }
            }
          }
        }
      }
    }

    mst = *list_of_mst.begin();
    result.insert(mst.mst);
  }

  // naive remove unique...
  return vector<vector<pair<int,int>>>(result.cbegin(),result.cend());
}
