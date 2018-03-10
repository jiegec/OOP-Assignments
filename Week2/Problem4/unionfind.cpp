#include "unionfind.h"

void UnionFind::feed_data(int n, int* command, int len) {
  this->n = n;
  parents = new int[n];
  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }
  for (int j = 0; j < len; j++) {
    int kind = command[j];
    if ((kind % 2) == 1) {
      // Merge
      int first = command[++j] % n;
      int second = command[++j] % n;
      merge(first, second);
    } else {
      // Query
      int query = command[++j] % n;
      parent(query);
    }
  }
}

void UnionFindNaive::merge(int a, int b) {
    int pa = parent(a);
    int pb = parent(b);
    for (int i = 0;i < n;i++) {
        if (parents[i] == pa) {
            parents[i] = pb;
        }
    }
}

int UnionFindNaive::parent(int a) {
    return parents[a];
}

void UnionFindOpt::merge(int a, int b) {
  int pa = parent(a);
  int pb = parent(b);
  parents[pa] = pb;
}

int UnionFindOpt::parent(int a) {
  if (parents[a] == a) {
    return a;
  } else {
    return parents[a] = parent(parents[a]);
  }
}