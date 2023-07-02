// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <algorithm>

using namespace std;

// recursive dynamic programming
int solve_recur(int n, const int* values, const int* weights, int* C, int avail) {
  // base
  if (avail <= 0) {
    return 0;
  }
  // memo
  int& r = C[avail];
  if (r >= 0)
    return r;

  // recursion
  r = 0;
  for (int i = 0; i < n; ++i) {
    if (weights[i] <= avail) {
      r = max(r, values[i] + solve_recur(n, values, weights, C, avail - weights[i]));
    }
  }
  return r;
}

// iterative dynamic programming
// O(CN) O(C)
int solve_iter(int n, const int* values, const int* weights, int capacity) {
    int* C = new int[capacity + 1];
    fill(C, C + capacity + 1, 0);
    for (int w = 0; w <= capacity; ++w) {
        for (int i = 0; i < n; ++i) {
            if (weights[i] <= w) {
                C[w] = max(C[w], values[i] + C[w - weights[i]]);
            }
        }
    }
    int ans = C[capacity];
    delete[] C;
    return ans;
}

int main() {
  int n = 3;
  int values[] = {10, 30, 20};
  int weights[] = {5, 10, 15};
  int capacity = 100;

  {
    int* C = new int[capacity + 1];
    fill(C, C + capacity + 1, -1);
    printf("%d\n", solve_recur(n, values, weights, C, capacity)); // 300
  }
  printf("%d\n", solve_iter(n, values, weights, capacity));  // 300

  return 0;
}
