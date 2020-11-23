/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/permutation-sequence/description/

#include <cstdio>
#include <string>
#include <vector>


class Solution {
 public:
  std::string getPermutation(int n, int k) {
    std::string r;
    std::vector<int> fcts(10, 1);
    for (int i = 1; i < 10; ++i) {      
      fcts[i] = fcts[i-1] * i;
    }
    std::string nums;
    for (int i = 0; i < n; ++i)
      nums += '1' + i;
    while (!nums.empty()) {
      int i;
      int unit = fcts[nums.size()] / nums.size();
      for (i = 0; i < nums.size(); ++i) {
        if (unit * (i+1) >= k)
          break;
      }
      r += nums[i];
      nums.erase(i, 1);
      k -= unit * i;
    }

    return r;
  }
};


int main() {
  Solution s;
  printf("%s\n", s.getPermutation(3, 3).c_str());
  printf("%s\n", s.getPermutation(4, 9).c_str());
  return 0;
}
