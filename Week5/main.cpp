#include <stdlib.h>
#include <time.h>
#include <set>
#include <math.h>
#include <utility>
#include <iostream>
#include <algorithm>

#include "graph.h"
#include "mst.h"

using namespace std;

float dist(pair<int, int> a, pair<int, int> b) {
  return sqrt((a.first - b.first) * (a.first - b.first) +
              (a.second - b.second) * (a.second - b.second));
}

int main() {
  Graph graph;
  srand(time(nullptr));
  const int num_points = 20;
  set<pair<int, int>> points;
  while (points.size() < num_points) {
    pair<int, int> new_point(rand() % 10001, rand() % 10001);
    points.insert(new_point);
  }
  vector<pair<int, int>> point_vec(points.cbegin(), points.cend());
  cout << "graph g {" << endl;
  for (int i = 0; i < num_points; i++) {
    graph.push_node(point_vec[i]);
    cout << i << " [pos=\"" << point_vec[i].first / 300.0 << ","
         << point_vec[i].second / 300.0 << "!\"];" << endl;
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
  for (int i = 0; i < resultPrim.size(); i++) {
    auto prim = resultPrim[i], kruskal = resultKruskal[i];
    if (prim != kruskal) {
      cout << "fail";
      return -1;
    }
  }
  for (auto it = resultPrim.cbegin(); it != resultPrim.cend(); it++) {
    cout << it->first << " -- " << it->second << " [label=\""
         << graph.get_weight(it->first, it->second) << "\"];" << endl;
  }
  cout << "}" << endl;

  cerr << "A graphviz format of the MST is printed into stdout. Use \"make "
          "test\" to convert to MST to a png and view it. (You might need to "
          "install graphviz and alter the command in the Makefile for it to "
          "work in your coputer)."
       << endl;
}
