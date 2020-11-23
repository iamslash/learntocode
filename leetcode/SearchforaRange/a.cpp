/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/802/

#include <cstdio>
#include <vector>

//               l
//               m
//               r
// 0 0 2 3 4 4 4 5
//
// 5

class Solution {
 public:
  std::vector<int> searchRange(std::vector<int>& v, int t) {
    // binary search first element of the target
    int l = 0, m, r = v.size()-1, a;
    while (l <= r) {
      m = (l+r)/2;
      a = v[m];

      // printf("%d %d %d\n", l, m, r);
      if (a == t) {
        // found it
        if (m == 0 || v[m-1] != a) {
          for (r = m; r < v.size() && v[r] == a; ++r)
            ;
          return std::vector<int>{m, r-1};
        } else {
          r = m;
        }
      } else if (a < t) {
        l = m+1;
      } else {
        r = m-1;
      }
    }
    return std::vector<int>{-1, -1};
  }
};

int main() {
  // std::vector<int> v = {5, 7, 7, 8, 8, 10};
  // int t = 8;
  // std::vector<int> v = {5, 7, 7, 8, 8, 10};
  // int t = 6;
  // std::vector<int> v = {1};
  // int t = 1;
  std::vector<int> v = {0, 0, 2, 3, 4, 4, 4, 5};
  int t = 5;
  
  Solution s;
  const auto r = s.searchRange(v, t);

  for (int a : r) {
    printf("%d ", a);    
  }
  printf("\n");
  
  return 0;
}
