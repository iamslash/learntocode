/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 3 2 4 1
// i
// 4 2 3 1 : 3
// 1 3 2 4 : 4
//   i
// 3 1 2 4 : 2
// 1 2 3 4 : 3

// 8ms 70.85% 8.6MB 75.68%
// brute force
// O(N^2) O(N)
class Solution {
 public:
  std::vector<int> pancakeSort(std::vector<int>& A) {
    std::vector<int> ans;
    int n = A.size();
    for (int i = 0; i < n; ++i) {
      int j = std::max_element(A.begin(), A.end() - i) - A.begin();
      std::reverse(A.begin(), A.begin() + j + 1);
      ans.push_back(j + 1);
      std::reverse(A.begin(), A.end() - i);
      ans.push_back(n - i);
    }
    return ans;
  }
};

int main() {
  return 0;
}
