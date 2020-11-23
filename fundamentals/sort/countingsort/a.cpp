// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

void counting_sort(std::vector<int>& V) {
  int n = V.size();
  int maxv = *max_element(V.begin(), V.end());
  int minv = *min_element(V.begin(), V.end());
  int range = maxv - minv + 1;
  std::vector<int> cnts(range, 0);
  std::vector<int> rslt(n);

  // set count vector
  for (int i = 0; i < n; ++i) {
    int j = V[i] - minv; // index for cnts
    cnts[j]++;
  }

  // set cumulative value
  for (int i = 1; i < cnts.size(); ++i)
    cnts[i] += cnts[i-1];

  // set result
  for (int i = 0; i < n; ++i) {
    int j = V[i] - minv;
    rslt[cnts[j]-1] = V[i];
    cnts[j]--;    
  }

  // set out V
  for (int i = 0; i < V.size(); ++i) {
    V[i] = rslt[i];
  }
}

void printv(std::vector<int>& V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

int main() {
  std::vector<int> V = {1, 1, 0, 3, 4, 5, 1, 0, 5, 5, 3, 1, 2, 2, 2, 2};
  
  counting_sort(V);
  
  printv(V);
  
  return 0;
}
