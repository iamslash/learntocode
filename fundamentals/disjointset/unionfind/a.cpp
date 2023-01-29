// Copyright (C) 2016 by iamslash

#include <vector>
#include <numeric>

using namespace std;

class NaiveDisjointSet {
  vector<int> prnts;
public:
  NaiveDisjointSet(int n) : prnts(n) {
    iota(begin(prnts), end(prnts), 0);
  }
  void merge(int a, int b) {
    prnts[find(b)] = find(a);
  }
  int find(int a) {
    return prnts[a] == a ? a : (prnts[a] = find(prnts[a]));
  }
  void reset(int a) {
    prnts[a] = a;
  }
};

struct OptimizedDisjointSet {
  vector<int> prnts, ranks;
  explicit OptimizedDisjointSet(int n) : prnts(n), ranks(n, 1) {
    iota(begin(prnts), end(prnts), 0);
  }
  int find(int a) {
    return prnts[a] == a ? a : (prnts[a] = find(prnts[a]));
  }
  void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return;
    if (ranks[u] > ranks[v])
      swap(u, v);
    // always ranks[v] > ranks[u] u should be child of v
    prnts[u] = v;
    if (ranks[u] == ranks[v])
      ++ranks[v];
  }
};

int main() {
  OptimizedDisjointSet uf(10);
  uf.merge(0, 5);
  uf.merge(4, 8);
}
