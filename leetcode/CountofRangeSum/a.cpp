/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

// 32ms 78.10% 25.5MB 50.00%
// merge sort
// O(NlgN) O(lgN)
class Solution {
 private:
  int mergeSort(std::vector<int64_t>& ps, int s, int e, int lower, int upper) {
    // base
    if (e - s <= 1)
      return 0;
    //recursion
    int m = s + (e - s) / 2, j = m, k = m, cnt = 0;
    cnt = mergeSort(ps, s, m, lower, upper) +
        mergeSort(ps, m, e, lower, upper);
    for (int i = s; i < m; ++i) {
      while (j < e && ps[j] - ps[i] < lower)
        ++j;
      while (k < e && ps[k] - ps[i] <= upper)
        ++k;
      cnt += k - j;
    }
    std::inplace_merge(ps.begin() + s, ps.begin() + m, ps.begin() + e);
    return cnt;
  }
 public:
  int countRangeSum(std::vector<int>& A, int lo, int up) {
    int n = A.size();
    std::vector<int64_t> ps(n+1,0);
    for (int i = 0; i < n; i++)
      ps[i+1] = ps[i] + A[i];
    return mergeSort(ps, 0, n+1, lo, up);
  }
};

void printV(const std::vector<int>& C) {
  for (auto i : C) {
    printf("%d ", i);
  }
  printf("\n");
}

int main() {

  std::vector<int> A = {1, 7, 7};
  std::vector<int> B = {2, 7, 9};
  std::vector<int> C;
  std::merge(A.begin(), A.end(), B.begin(), B.end(), std::back_inserter(C));
  printV(C);

  std::vector<int> D = {1, 7, 7, 2, 7, 9};
  std::inplace_merge(D.begin(), D.begin()+3, D.end());
  printV(D);
  
  return 0;
}
