/* Copyright (C) 2022 by iamslash */

#include <cstdio>

using namespace std;

#include <vector>
#include <set>

// Wrong Answer For:
// [1, 2, 3]
// sliding window, set
// O(N) O(N)
class Solution {
public:
  bool findSubarrays(vector<int>& nums) {
    int n = nums.size();
    set<int> sumSet;
    for (int i = 1; i < n; ++i) {
      int sum = nums[i-1] + nums[i];
      if (sumSet.find(sum) != sumSet.end()) {
        return true;
      }
      sumSet.insert(sum);
    }
    return true;
  }
};

int main() {
  return 0;
}
