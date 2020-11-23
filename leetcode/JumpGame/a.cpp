/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/807/

#include <cstdio>
#include <vector>

//         i             
//         r            
// 2 3 1 1 4
//    

//         i
//       r
// 3 2 1 0 4

class Solution {
 public:
  bool canJump(std::vector<int>& v) {
    int r = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (i > r)
        break;
      r = std::max(r, i + v[i]);
    }
    return r >= v.size() - 1;    
  }
};

int main() {
  Solution s;
  // std::vector<int> v = {2, 3, 1, 1, 4};
  std::vector<int> v = {3, 2, 1, 0, 4};
  
  printf("%s\n", s.canJump(v) ? "true" : "false");
  return 0;
}
