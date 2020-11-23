/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 6.3MB 50.00%
// linear traversal
// O(N) O(1)
class Solution {
 public:
  int maxDepth(string s) {
    int maxDepth = 0;
    int depth = 0;
    for (char c : s) {
      if (c == '(') {
        depth++;
        maxDepth = max(maxDepth, depth);
      } else if (c == ')') {
        depth--;
      }
    }
    return maxDepth;
  }
};
