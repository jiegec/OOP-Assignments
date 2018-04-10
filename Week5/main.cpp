#include <stdlib.h>
#include <time.h>
#include <set>
#include <math.h>
#include <utility>
#include <iostream>
#include <fstream>
#include <algorithm>

#include "graph.h"
#include "mst.h"

using namespace std;

float dist(pair<int, int> a, pair<int, int> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}

// print the edges into a graphviz file
void print_edges(const Graph& graph,
                 const vector<pair<int, int>>& point_vec,
                 const vector<pair<int, int>>& edges,
                 const char* filename) {
  ofstream mst(filename);
  mst << "graph g {" << endl;
  auto num_points = point_vec.size();
  for (auto i = 0; i < num_points; i++) {
    mst << i << " [pos=\"" << point_vec[i].first / 300.0 << ","
        << point_vec[i].second / 300.0 << "!\"];" << endl;
  }

  for (auto it = edges.cbegin(); it != edges.cend(); it++) {
    mst << it->first << " -- " << it->second << " [label=\""
        << graph.get_weight(it->first, it->second) << "\"];" << endl;
  }
  mst << "}" << endl;
}

int main(int argc, char* argv[]) {
  Graph graph;
  srand(time(nullptr));
  const int num_points = 20;
  // randomly generate num_points of unique points
  set<pair<int, int>> points;
  while (points.size() < num_points) {
    pair<int, int> new_point(rand() % 10001, rand() % 10001);
    points.insert(new_point);
  }
  vector<pair<int, int>> point_vec(points.cbegin(), points.cend());
  for (int i = 0; i < num_points; i++) {
    graph.push_node(point_vec[i]);
  }
  for (int i = 0; i < num_points; i++) {
    for (int j = i + 1; j < num_points; j++) {
      graph.push_edge(i, j, dist(point_vec[i], point_vec[j]));
    }
  }
  auto resultPrim = PrimMST::computeMST(graph);
  auto resultKruskal = KruskalMST::computeMST(graph);
  sort(resultPrim.begin(), resultPrim.end());
  sort(resultKruskal.begin(), resultKruskal.end());
  // compare the reslt of Prim and Kruskal
  // they should be the same all the time
  for (int i = 0; i < resultPrim.size(); i++) {
    auto prim = resultPrim[i], kruskal = resultKruskal[i];
    if (prim != kruskal) {
      cerr << "My algorithm does not report the same MST.";
      return -1;
    }
  }

  print_edges(graph, point_vec, resultPrim, "mst.dot");

  auto resultAAK = AmalAjishKumarMST::computeTopKMST(graph, 10);
  for (int i = 0; i < resultAAK.size(); i++) {
    char name[128];
    sprintf(name, "mst%d.dot", i + 1);
    print_edges(graph, point_vec, resultAAK[i], name);
  }

  cout << "A graphviz format of the MST is printed into mst.dot. Use \"make "
          "test\" to convert to MST to a png and view it. (You might need to "
          "install graphviz and alter the command in the Makefile for it to "
          "work in your coputer)."
       << endl;

  // generate graphviz
  if (argc == 2) {
    system("dot -Kfdp -n -Tpng -o mst.png mst.dot");
    for (int i = 0; i < resultAAK.size(); i++) {
      char name[128];
      sprintf(name, "dot -Kfdp -n -Tpng -o mst%d.png mst%d.dot", i + 1, i + 1);
      system(name);
    }
  }
  return 0;
}
