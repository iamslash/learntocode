// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void printv(std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

void bubble_sort(std::vector<int>& V) {
  int n = V.size();
  bool bswap = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n-i-1; ++j) {
      if (V[j] > V[j+1]) {
        std::swap(V[j], V[j+1]);
        bswap = true;
      }
    }
    if (bswap == false)
      break;
  }
}

int main() {
  std::vector<int> V = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};
  
  bubble_sort(V);
  
  printv(V);
  
  return 0;
}
