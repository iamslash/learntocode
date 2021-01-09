// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void insert_sort(std::vector<int>& V) {
  for (int i = 0; i < V.size(); ++i) {
    for (int j = i; j > 0 && V[j] < V[j-1]; --j) {
      std::swap(V[j-1], V[j]);
    }
  }
}

int main()
{
  std::vector<int> v = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};

  insert_sort(v);

  printv(v);

  return 0;
}
