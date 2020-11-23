// Copyright (C) 2018 by iamslash
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

#include <cstdio>
#include <vector>

// 0 1 2 3 4 5 6
// l
// m
//   r
// 1 3
class Solution {
 public:
  bool search(std::vector<int>& v, int t) {
    int l = 0, m, r = v.size();
    while (l <= r) {
      // while (l+1 < r && v[l] == v[l+1])
      //   l++;
      m = (l+r)/2;
      printf("%d %d %d\n", l, m, r);
      if (v[m] < t) {
        if (t < v[l] || v[l] < v[m])
          l = m + 1;
        else
          r = m;
      } else if (v[m] > t) {
        if (v[l] <= t || v[l] >= v[m])
          r = m;
        else
          l = m + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};

int main() {
  // std::vector<int> v = {2, 5, 6, 0, 0, 1, 2};
  // int t = 0;
  // std::vector<int> v = {2, 5, 6, 0, 0, 1, 2};
  // int t = 3;
  // std::vector<int> v = {1, 3};
  // int t = 3;
  // std::vector<int> v = {3, 5, 1};
  // int t = 2;
  // std::vector<int> v = {1};
  // int t = 1;
  std::vector<int> v = {1, 3};
  int t = 3;

  Solution s;
  printf("%s\n", s.search(v, t) ? "true" : "false");
  
  return 0;
}
