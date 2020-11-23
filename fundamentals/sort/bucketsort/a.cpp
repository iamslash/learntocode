/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

#define BSIZE 5

void printv(std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

void bucket_sort(std::vector<int>& V) {
  int n = V.size();
  int maxv = *std::max_element(V.begin(), V.end());
  int div  = std::ceil((maxv + 1) / BSIZE);
  std::vector<int> B[BSIZE];

  for (int i = 0; i < n; ++i) {
    int j = V[i] / div;
    B[j].push_back(V[i]);
  }

  int j = 0;
  for (int i = 0; i < BSIZE; ++i) {
    auto& l = B[i];
    if (!l.empty()) {
      std::sort(l.begin(), l.end());
      for (int a : l) {
        V[j++] = a;
      }
    }    
  }   
}


int main()
{
  std::vector<int> V = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};

  bucket_sort(V);

  printv(V);

  return 0;
}
