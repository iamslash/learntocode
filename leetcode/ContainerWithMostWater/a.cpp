/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/container-with-most-water/description/

#include <cstdio>
#include <vector>

class Solution {
 public:
  int maxArea(std::vector<int>& h) {
    int rr = 0;
    int l = 0, r = h.size()-1;
    while (l < r) {
      //
      int area = (r-l) * std::min(h[l], h[r]);
      rr = std::max(rr, area);
      if (h[l] < h[r])
        l++;
      else
        r--;
    }
    return rr;
  }
};

int main() {
  // std::vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  std::vector<int> h = {2, 3, 4, 5, 18, 17, 6};
  Solution s;
  printf("%d\n", s.maxArea(h));
  return 0;
}
