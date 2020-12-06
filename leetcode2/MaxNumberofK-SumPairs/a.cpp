/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// nums: 3 1 3 4 3
// cnts: 1 3 4
//       1 3 1

// 6

// 280ms 100.00% 68.2MB 33.33%
// hash map
// O(N) O(N)
class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> cnts;
    for (int num : nums) {
      cnts[num]++;
    }
    int ans = 0;
    for (auto& pr : cnts) {
      int numA = pr.first;
      int cntA = pr.second;
      int numB = k - numA;
      if (numB <= 0 || cnts.count(numB) == 0) {
        continue;
      }
      int cntB = cnts[numB];
      if (numA * 2 == k) {
        cntB = (cntB / 2) * 2;
      }
      ans += min(cntA, cntB);
    }
    return ans / 2;
  }
};
