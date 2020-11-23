/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& v) {

  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void shell_sort(std::vector<int>& V) {
  int n = V.size();
  int h = 1;
  // 3x+1 increment sequence: 1, 4, 13, 40, 121, 364, 1093,...
  while (h < n/3)
    h = 3 * h + 1;
  while (h >= 1) {
    for (int i = h; i < n; ++i) {
      for (int j = i; j >= h && V[j] < V[j-h]; j -= h) {
        std::swap(V[j], V[j-h]);
      }
    }
    h /= 3;
  }
}

int main()
{
  std::vector<int> v = {1, 5, 4, 3, 13, 14, 15, 2, 10, 11, 12, 7, 6, 8, 9};

  shell_sort(v);

  printv(v);

  return 0;
}
