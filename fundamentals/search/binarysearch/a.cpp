// Copyright (C) 2021 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>

int bs_right_most(std::vector<int>& A, int k) {
  int l = 0, r = A.size() - 1, m = 0;
  while (l < r) {
    int m = (l+r+1)/2;
    if (A[m] < k) {
      l = m;
    } else {
      r = m-1;
    }
  }
  return A[l];
}

int bs_right_most_equal(std::vector<int>& A, int k) {
  int l = 0, r = A.size() - 1, m = 0;
  while (l < r) {
    int m = (l+r+1)/2;
    if (A[m] <= k) {
      l = m;
    } else {
      r = m-1;
    }
  }
  return A[l];
}

int bs_left_most_equal(std::vector<int>& A, int k) {
  int l = 0, r = A.size() - 1, m = 0;
  while (l < r) {
    int m = (l+r)/2;
    if (A[m] < k) {
      l = m+1;
    } else {
      r = m;
    }
  }
  return A[l];
}

int bs_left_most(std::vector<int>& A, int k) {
  int l = 0, r = A.size() - 1, m = 0;
  while (l < r) {
    int m = (l+r)/2;
    if (A[m] <= k) {
      l = m+1;
    } else {
      r = m;
    }
  }
  return A[l];
}

int main()
{
  std::vector<int> v = {1, 2, 3, 5, 6, 7};
  printf("%d\n", bs_right_most(v, 4));       // 3
  printf("%d\n", bs_right_most(v, 5));       // 3
  printf("%d\n", bs_right_most_equal(v, 4)); // 3
  printf("%d\n", bs_right_most_equal(v, 5)); // 5
  printf("%d\n", bs_left_most_equal(v, 4));  // 5
  printf("%d\n", bs_left_most_equal(v, 5));  // 5
  printf("%d\n", bs_left_most(v, 4));        // 5
  printf("%d\n", bs_left_most(v, 5));        // 6
  return 0;
}
