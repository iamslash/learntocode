/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// 2010

// 0ms 100.00%
// O(1) O(1)
class Solution {
 public:
  int nextGreaterElement(int n) {
    std::string s = std::to_string(n);
    std::next_permutation(s.begin(), s.end());
    int64_t r = std::stoll(s);
    return (r >= INT_MAX || r <= n) ? -1 : r;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.nextGreaterElement(3100));
  
  return 0;
}
