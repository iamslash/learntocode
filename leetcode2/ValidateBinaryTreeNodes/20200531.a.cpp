/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>

using namespace std;


//    0
//   / \
//  1   2
//     /
//    3

//            0
//           /
//          1
//         /
//        2

// 4
// [1,2,0,-1]
// [-1,-1,-1,-1]
// 1 2 0

// false conditions
//
// 0. visit again
// 1. visit n - 1 times except root node

// 108ms 35.97% 33.9Mb 100.00%
// hash set
// O(N) O(N)
class Solution {
 public:
  bool validateBinaryTreeNodes(int n, vector<int>& L, vector<int>& R) {
    unordered_set<int> seen;
    for (int i = 0; i < n; ++i) {
      if (L[i] >= 0) {
        if (!seen.insert(L[i]).second)
          return false;
      }
      if (R[i] >= 0) {
        if (!seen.insert(R[i]).second)
          return false;
      }
      if (L[i] == -1 && R[i] == -1 && !seen.empty() && seen.count(i) == 0)
        return false;        
    }
    return seen.size() == n - 1;
  }
};
