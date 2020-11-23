/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

// i
// 1 1 1 3 3 2 2 2
// can0 : 0
// cnt0 : 0
// can1 : 1
// cnt1 : 0
//
// 8ms 99.98%
static int __ = [](){
  std::ios_base::sync_with_stdio(NULL);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  return 0;
}();
class Solution {
 public:
  std::vector<int> majorityElement(std::vector<int>& V) {
    std::vector<int> rslt;
    if (V.empty())
      return rslt;
    int cnt0 = 0, cnt1 = 0, can0 = 0, can1 = 1;
    for (int v : V) {
      if (v == can0) {
        cnt0++;
      } else if (v == can1) {
        cnt1++;
      } else if (cnt0 == 0) {
        can0 = v;
        cnt0 = 1;
      } else if (cnt1 == 0) {
        can1 = v;
        cnt1 = 1;
      } else {
        cnt0--;
        cnt1--;
      }
    }
    cnt0 = cnt1 = 0;
    for (int v : V) {
      if (v == can0)
        cnt0++;
      if (v == can1)
        cnt1++;
    }
    if (cnt0 > V.size()/3)
      rslt.push_back(can0);
    if (cnt1 > V.size()/3)
      rslt.push_back(can1);

    return rslt;
  }
};

int main() {
  std::vector<int> V0 = {3, 2, 3};
  std::vector<int> V1 = {1, 1, 1, 3, 3, 2, 2, 2};

  Solution sln;

  auto rslt = sln.majorityElement(V1);
  for (int a : rslt) {
    printf("%d ", a);
  }
  printf("\n");
  
  return 0;
}
