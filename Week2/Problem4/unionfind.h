#ifndef __UNIONFIND_H__
#define __UNIONFIND_H__

class UnionFind {
 public:
  void feed_data(int n, int* command, int len);

 protected:
  int n;
  int* parents;
  virtual void merge(int a, int b) = 0;
  virtual int parent(int a) = 0;
};

class UnionFindNaive : public UnionFind {
  void merge(int a, int b) override;
  int parent(int a) override;
};

class UnionFindOpt : public UnionFind {
  void merge(int a, int b) override;
  int parent(int a) override;
};

#endif