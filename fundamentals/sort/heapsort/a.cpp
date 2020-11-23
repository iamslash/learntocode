/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

// build heap
void heapify(std::vector<int>& V, int i, int n) {
  int k, child;
  for (k = V[i]; 2 * i + 1 < n; i = child) {
    child = 2 * i + 1;
    if (child != n - 1 && V[child] < V[child+1])
      ++child;
    if (k < V[child])
      V[i] = V[child];
    else
      break;
  }
  V[i] = k;
}

void heap_sort(std::vector<int>& V) {
  int n = V.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    heapify(V, i, n);
  }
  for (int i = n-1; i > 0; --i) {
    std::swap(V[0], V[i]);
    heapify(V, 0, i);
  }
}

int main() {
  std::vector<int> v = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};

  heap_sort(v);

  printv(v);

  return 0;
}
