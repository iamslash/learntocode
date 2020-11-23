// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/MEASURETIME

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstdint>

int N;

int64_t solve(std::vector<int>& v, int left, int right) {
  // base condition
  if (left == right)
    return 0;
  // recursion
  int mid = (left + right) / 2;
  int64_t r = solve(v, left, mid) + solve(v, mid+1, right);

  std::vector<int> tmp(right - left + 1);
  int idx_tmp = 0;
  int idx_left = left;
  int idx_right = mid + 1;
  while (idx_left <= mid || idx_right <= right) {
    if (idx_left <= mid &&
        (idx_right > right || v[idx_left] <= v[idx_right])) {
          tmp[idx_tmp++] = v[idx_left++];
    } else {
      r += mid - idx_left + 1;
      tmp[idx_tmp++] = v[idx_right++];
    }
      
  }
  for (int i = 0; i < tmp.size(); ++i) {
    v[left + i] = tmp[i];
  }
  return r;
}
  
int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> v(N);
    for (int i = 0; i < N; ++i)
      scanf("%d", &v[i]);
    printf("%lu\n", solve(v, 0, v.size() - 1));
  }
  return 0;
}
