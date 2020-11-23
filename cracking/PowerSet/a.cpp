// Copyright (C) 2017 by iamslash

// Power Set: Write a method to return all subsets of a set.

#include <cstdio>
#include <vector>

int N;
std::vector<int> V;

std::vector<std::vector<int> > solve_iterative() {
  //
  std::vector<std::vector<int> > r;
  r.push_back(std::vector<int>());
  for (int i = 0; i < V.size(); ++i) {
    std::vector<std::vector<int> > prev_r(r);
    for (const std::vector<int> set : prev_r) {
      std::vector<int> new_set(set);
      new_set.push_back(V[i]);
      r.push_back(new_set);
    }
  }
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    V.resize(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &V[i]);
    }
    std::vector<std::vector<int> > v;
    std::vector<std::vector<int> > r = solve_iterative();
    for (const std::vector<int>& v : r) {
      for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
      printf("\n");
    }
  }
  return 0;
}
