/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

void printv(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    printf("%d ", v[i]);
  printf("\n");
}

void count_sort(std::vector<int>& V, int exp) {
  int n = V.size();
  std::vector<int> cnts(10, 0);
  std::vector<int> rslt(n, 0);
  for (int i = 0; i < n; ++i)
    cnts[(V[i]/exp)%10]++;
  for (int i = 1; i < 10; ++i)
    cnts[i] += cnts[i-1];
  for (int i = n-1; i >= 0; --i) {
    int j = (V[i]/exp)%10;
    rslt[cnts[j]-1] = V[i];
    cnts[j]--;
  }
  for (int i = 0; i < n; ++i)
    V[i] = rslt[i];
}

void radix_sort(std::vector<int>& V) {
  int maxv = *std::max_element(V.begin(), V.end());
  for (int exp = 1; maxv / exp > 0; exp *= 10) {
    count_sort(V, exp);
  }
}

int main() {
  std::vector<int> v = {1, 5, 4, 3, 2, 10, 7, 6, 8, 9};

  radix_sort(v);

  printv(v);

  return 0;
}
