// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

#define LSB(i) ((i) & -(i)) 
struct FenwickTree {
  vector<int> tree;
  FenwickTree(int n) : tree(n+1) {
  }
  int sum(int i)
  {
    int sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= LSB(i);
    }
    return sum;
  }
  void add(int i, int k) {
    while (i <= tree.size()) { 
      tree[i] += k;
      i += LSB(i);
    }
  }
};

int main () {
  int N = 5;
  FenwickTree ft(N);
  for (int i = 0; i < N; ++i)
    ft.add(i, i + 1);

  printf("%d\n", ft.sum(4));
  return 0;
}
