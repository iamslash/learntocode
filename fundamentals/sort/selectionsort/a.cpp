/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& v) {

  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void selection_sort(std::vector<int>& V) {
  int n = V.size();  
  int mi;

  for (int i = 0; i < n-1; ++i) {
    mi = i;
    for (int j = i+1; j < n; ++j) {
      if (V[j] < V[mi])
        mi = j;
    }
    std::swap(V[i], V[mi]);
  }
}

int main()
{
  std::vector<int> v = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};

  selection_sort(v);

  printv(v);

  return 0;
}
