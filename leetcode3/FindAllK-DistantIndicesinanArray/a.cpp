/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

// 858ms 10.00% 11.9MB 30.00%
// sort, hash set
// O(NlgN) O(N)
class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    set<int> idxSet;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != key) {
        continue;
      }
      for (int j = 0; j <= k; ++j) {
        if (i-j >= 0) {
          idxSet.insert(i-j);
        }
        if (i+j < n) {
          idxSet.insert(i+j);
        }
      }
    }
    vector<int> ans(idxSet.begin(), idxSet.end());
    sort(ans.begin(), ans.end());
    return ans;
  }
};

// 6ms 90.00% 10.4MB 30.00%
// brute force
// O(N) O(N)
class Solution {
public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] != key) {
          continue;
      }
      int fr = max(ans.empty() ? 0 : ans.back() + 1, i - k);
      int to = min(n-1, i + k);
      for (int j = fr; j <= to; ++j) {
        ans.push_back(j);
      }
    }
    return ans;
  }
};
  
int main() {
  return 0;
}
