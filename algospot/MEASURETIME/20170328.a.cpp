// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/FAMILYTREE

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <limits>

int N;
std::vector<int> A;

struct FenwickTree {
  std::vector<int> tree;
  explicit FenwickTree(int n) : tree(n+1) {}
  int sum(int pos) {
    ++pos;
    int r = 0;
    while (pos > 0) {
      r += tree[pos];
      pos &= (pos - 1);
    }

    return r;
  }
  void add(int pos, int val) {
    ++pos;
    while (pos < tree.size()) {
      tree[pos] += val;
      pos += (pos & -pos);
    }
  }
};

int64_t count_moves(const std::vector<int>& v) {
  FenwickTree tree(1000000);
  int64_t r = 0;
  for (int i = 0; i < v.size(); ++i) {
    r += tree.sum(999999) - tree.sum(A[i]);
    tree.add(v[i], 1);
  }
  return r;
}
  
int main() {
  int T;
  scanf("%d", &T);

  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    A.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    printf("%lld\n", count_moves(A));
  }
  //
  return 0;
}
