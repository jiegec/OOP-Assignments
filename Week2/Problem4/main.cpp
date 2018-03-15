#include "timer.h"
#include "unionfind.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;


double test_func(const char* name, UnionFind& tested_class, int arr[], int len) {
  printf("%s: Begin testing.\n", name);
  timer_begin();
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 1000; j++) {
      tested_class.feed_data(100, arr, len);
    }
  }
  double time = timer_end();
  printf("%s: %.2lf time elapsed.\n", name, time);
  return time;
}

int main(int argc, char* argv[]) {
  const int n = 100;
  int arr[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    arr[i] = rand() % 1000 + 1;
  }
  UnionFindNaive uf_naive;
  UnionFindOpt uf_opt;
  double naive = test_func("naive uf", uf_naive, arr, n);
  double opt = test_func("optimized uf", uf_opt, arr, n);

  printf("Optimized UnionFind over Naive: %.2lf\n", (naive - opt) / naive);

  return 0;
}
