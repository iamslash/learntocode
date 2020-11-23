/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// ( ( ( ( ( ) ) ) ) )
// 1 2 3 4 5 5 4 3 2 1
// 1 0 1 0 1 1 0 1 0 1
//
// A: ( ( ( ) ) )    B: ( ( ) )
//    1 3 5 5 3 1       2 4 4 2
//
// ( ( ) ) ( ( ( ) ) )
// 1 2 2 1 1 2 3 3 2 1
// 1 0 0 1 1 0 1 1 0 1
//
// A: ( ) ( ( ) )    B: ( ) ( )
//    1 1 1 3 3 1       2 2 2 2
// 

// 24ms 56.21% 9.5MB 100.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  std::vector<int> maxDepthAfterSplit(std::string seq) {
    std::vector<int> ans(seq.size(), 0);
    int lvl = 0, idx = 0;
    while (idx < seq.size()) {
      if (seq[idx] == '(')
        ans[idx] = ++lvl % 2;
      else
        ans[idx] = lvl-- % 2;
    }
    return ans;
  }
};

int main() {
  return 0;
}
