/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/834/

#include <cstdio>
#include <vector>

//     f             
//         s     
// 1 3 4 2 2
//
class Solution {
 public:
  int findDuplicate(const std::vector<int>& V) {
    if (V.empty())
      return -1;

    int slow = V[0];
    int fast = V[V[0]];

    while (slow != fast) {
      slow = V[slow];
      fast = V[V[fast]];
    }
    fast = 0;
    while (fast != slow) {
      fast = V[fast];
      slow = V[slow];
    }
    return slow;
  }
};

// s: 1 3 2 4 2 4 2 4 2 4 2 4 2 ...
// f: 3 4 4 4 
// f:         1 2 2
int main() {
  // std::vector<int> v = {1, 3, 4, 2, 2};
  std::vector<int> v = {3, 1, 3, 4, 2};

  Solution s;
  printf("%d\n", s.findDuplicate(v));

  return 0;
}
