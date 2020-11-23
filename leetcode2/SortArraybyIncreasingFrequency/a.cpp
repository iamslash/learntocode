/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 24ms 66.67% 11.5MB 100.00%
// sort, hash map
// O(NlgN) O(N)
class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    unordered_map<int, int> freqMap;
    for (int a : nums) {
      freqMap[a]++;
    }
    sort(nums.begin(), nums.end(), [&](int a, int b) {
                                     if (freqMap[a] == freqMap[b]) {
                                       return a > b;
                                     }
                                     return freqMap[a] < freqMap[b];
                                   });
    return nums;
  }
};
