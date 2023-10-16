/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;

// freq: cnt
//    1: -1
//    2:  1
//    3:  1
//    4:  2
//    5:  2
//    6:  2

// 132ms 29.58% 85.1MB 92.42%
// hash map
// O(N) O(N)
class Solution {
public:
  int minOperations(vector<int>& nums) {
    unordered_map<int, int> cnt_map;
    for (int num : nums) {
      cnt_map[num]++;
    }
    int ans = 0;
    for (auto it = cnt_map.begin(); it != cnt_map.end(); ++it) {
      int key = (*it).first, val = (*it).second;
      if (val == 1) {
        return -1;
      }
      ans += (val + 2) / 3;
    }
    return ans;
  }
};

int main() {
  return 0;
}
