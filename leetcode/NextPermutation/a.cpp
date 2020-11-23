/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/next-permutation/description/

#include <cstdio>
#include <vector>
#include <algorithm>

// 1 2 5 4 3
// 1 3 2 4 5

// 4ms 100%
// O(N) O(1)
#include <iostream>
int x= []() { 
	std::ios::sync_with_stdio(false); 
        std::cin.tie(NULL);  
	return 0; 
}();
class Solution {
 public:
  void nextPermutation(std::vector<int>& v) {
    if (v.size() <= 1)
      return;
    // std::reverse(v.begin(), v.end());
    int ii = -1;
    for (int i = v.size()-2; i >= 0; --i) {
      if (v[i] < v[i+1]) {
        ii = i;
        break;
      }
    }
    // last permutation
    if (ii < 0) {
      std::reverse(v.begin(), v.end());
      return;
    }
      
    //
    int jj;
    int mm = std::numeric_limits<int>::max();
    for (int j = v.size()-1; j > ii; --j) {
      int d = v[j] - v[ii];
      if (d > 0 && d < mm) {
        mm = d;
        jj = j;
      }
    }
    //
    // printf("%d %d\n", ii, jj);
    std::swap(v[ii], v[jj]);
    std::reverse(v.begin()+ii+1, v.end());
  }
};

int main() {
  // std::vector<int> v = {1, 2, 3};
  // std::vector<int> v = {3, 2, 1};
  // std::vector<int> v = {1, 1, 5};
  // std::vector<int> v = {2, 3, 1};
  std::vector<int> v = {2, 3, 1, 3, 3};

  Solution s;
  s.nextPermutation(v);
  for (int a : v) {
    printf("%d ", a);
  }
  printf("\n");
  return 0;
}
