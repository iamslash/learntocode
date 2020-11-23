// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MEASURETIME

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstdint>

int N;

struct FenwickTree {
  std::vector<int> m_tree;
  FenwickTree(int n) : m_tree(n+1) {}
  int sum(int pos) {
    ++pos;
    int r = 0;
    while (pos > 0) {
      r += m_tree[pos];
      pos &= (pos - 1);
    }
    return r;
  }
  void add(int pos, int val) {
    ++pos;
    while (pos < m_tree.size()) {
      m_tree[pos] += val;
      pos += (pos & -pos);
    }    
  }
};


int64_t solve(const std::vector<int>& v) {
  FenwickTree ft(N+1);
  int64_t r = 0;
  for (int i = 0; i < v.size(); ++i) {
    r += ft.sum(N) - ft.sum(v[i]);
    ft.add(v[i], 1);
  }
  return r;
}
  
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> v(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &v[i]);
    printf("%lu\n", solve(v));
  }
  return 0;
}
