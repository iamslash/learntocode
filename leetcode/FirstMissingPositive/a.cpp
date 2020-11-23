/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/832/

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>

// O(N) O(N)
// 4ms, 80.83%
// class Solution {
//  public:
//   int firstMissingPositive(std::vector<int>& v) {
//     if (v.empty())
//       return 1;
//     int r = v[0];
//     int mm = *std::max_element(v.begin(), v.end());
//     std::unordered_set<int> s(v.begin(), v.end());
//     for (int i = 1; i <= mm; ++i) {
//       if (s.find(i) == s.end()) {
//         return i;
//       }
//     }
//     return mm+1;
//   }
// };

// The Best Solution
// O(N) O(1)
// 0ms 100%
#include <iostream>

static std::vector<int> nums=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return std::vector<int>{};
}();
class Solution {
 public:
  int firstMissingPositive(std::vector<int>& v) {
    // place number to right index slot
    for (int i = 0; i < v.size(); ++i) {
      while (v[i] > 0 && v[i] <= v.size() && v[v[i]-1] != v[i])
        std::swap(v[v[i]-1], v[i]);
    }
    for (int i = 0; i < v.size(); ++i) {
      printf("%d ", v[i]);
      if (v[i] != i+1)
        return i+1;
    }
    
    return v.size()+1;
  }
};

int main() {
  // std::vector<int> v = {7, 8, 9, 11, 12};
  // std::vector<int> v = {1, 2, 0};
  // std::vector<int> v = {};
  std::vector<int> v = {3, 4, -1, 1};
  
  Solution s;
  printf("%d\n", s.firstMissingPositive(v));
  return 0;
}
