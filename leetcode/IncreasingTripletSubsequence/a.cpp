// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/781/

#include <cstdio>
#include <vector>
#include <limits>

class Solution {
 public:
  bool increasingTriplet(std::vector<int>& nums) {
    int a = std::numeric_limits<int>::max();
    int b = std::numeric_limits<int>::max();
    for (int n : nums) {
      // printf("%d ", n);
      if (n <= a) {
        a = n;
      } else if (n <= b) {
        b = n;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  std::vector<int> v = {1, 2, 3, 4, 5};
  // std::vector<int> v = {5, 4, 3, 2, 1};
  printf("%s\n", s.increasingTriplet(v) ? "true" : "false");

  return 0;
}
