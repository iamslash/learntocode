/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/111/dynamic-programming/810/

#include <cstdio>
#include <vector>
#include <algorithm>

// // -2 -1
// class Solution {
//  public:
//   std::vector<int> V;
//   std::vector<int> C;  // C[i]: longest seq cnt of i idx
//   int _solve(int a) {
//     // base condition
//     if (a == V.size()-1)
//       return 1;
//     else if (a >= (int)V.size())
//       return 0;
    
//     // memoization
//     int& r = C[a];
//     if (r >= 0)
//       return r;
//     // printf("%d\n", a);
    
//     // recursion
//     r = 0;
//     for (int i = 1; i < (int)V.size(); ++i) {
//       if (V[a] < V[a+i])
//         r = std::max(r, 1 + _solve(a+i));
//     }
//     return r;
//   }
//   int lengthOfLIS(std::vector<int>& nums) {
//     if (nums.empty())
//       return 0;
//     else if (nums.size() == 1)
//       return 1;
//     V = nums;
//     C = std::vector<int>(V.size(), -1);
//     int r = 0;
//     for (int i = 0; i < V.size(); ++i) {
//       r = std::max(r, _solve(i));
//     }
//     return r;
//   }
// };

//     i
//       r
// 1 3 4 3 4
//         x
//
class Solution {
 public:
  int lengthOfLIS(std::vector<int> &a) {
    int r = 0;
    for (int x : a) {
      int i = std::lower_bound(a.begin(), a.begin() + r, x) - a.begin();
      if (i == r)
        ++r;
      a[i] = x;
      // printf("x: %d r:%d i:%d A: ", x, r, i);
      // for (int k = 0; k < a.size(); ++k)
      //   printf("%d ", a[k]);
      // printf("\n");
    }
    return r;
  }
};

int main() {
  // std::vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
  // std::vector<int> v = {0};
  // std::vector<int> v = {-2, -1};
  // std::vector<int> v = {10, 22, 9, 33, 21, 50, 41, 60, 80};
  std::vector<int> v = {6, 1, 5, 3, 4};
  Solution s;
  printf("%d\n", s.lengthOfLIS(v));  

  // std::vector<int> v = {10, 9, 2, 5, 3, 7, 101, 18};
  // std::sort(v.begin(), v.end());
  // for (int a : v)
  //   printf("%d ", a);
  // printf("\n");
  // int x = 3;
  // printf("%d\n", std::lower_bound(v.begin(), v.end(), x) - v.begin());
  // printf("%d\n", std::upper_bound(v.begin(), v.end(), x) - v.begin());

  return 0;
}
