/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/3sum-closest/description/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

// a + b + c = r
// t - r
//
//  1
//
// -3 0 1 2
//  i 
//    j
//        k
//  
// -1 -2
// 
class Solution {
public:
  int threeSumClosest(std::vector<int>& v, int t) {
    int rs = v[0] + v[1] + v[2];
    std::sort(v.begin(), v.end());
    // i, j, k
    int i, j, k;
    for (i = 0; i < v.size(); ++i) {
      int a = v[i];
      j = i+1;
      k = v.size()-1;
      while (j < k) {
        int b = v[j];
        int c = v[k];
        // current sum, current dist
        int cs = a + b + c;
        int cd = std::abs(t - cs);
        int rd = std::abs(t - rs);
        if (cd < rd) {
          rs = cs;
        }
        if (cs > t) {
          k--;
        } else {
          j++;
        }
      }
    }
    return rs;
  }
};

int main() {
  // std::vector<int> v = {-1, 2, 1, -4};
  // int t = 1;
  std::vector<int> v = {0, 2, 1, -3};
  int t = 1;
  Solution s;
  printf("%d\n", s.threeSumClosest(v, t));
  return 0;
}
