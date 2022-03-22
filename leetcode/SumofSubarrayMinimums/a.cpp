/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdint>

using namespace std;

//         i
//   nums: 3 1 2 4 1
//             j 
//  lefts: - - 1 2 1
// rights: 1 5 4 4 5
//                 i


void dump(const vector<int>& A) {
    for (int num : A) {
        printf("%d ", num);
    }
    printf("\n");
}
// 80ms 95.76% 41.7MB 69.53%
// hash map
// O(N) O(N)
class Solution {
public:
  int sumSubarrayMins(vector<int>& nums) {
    int64_t ans = 0;
    int n = nums.size(), MOD = 1000000007;
    vector<int> lefts(n, 0), rights(n, 0);
    // build lefts
    for (int i = 0; i < n; ++i) {
      int j = i - 1;
      while (j >= 0 && nums[j] > nums[i]) {
        j = lefts[j];
      }
      lefts[i] = j;
    }
    // build rights, ans
    for (int i = n-1; i >= 0; --i) {
      int j = i + 1;
      while (j < n && nums[i] <= nums[j]) {
        j = rights[j];
      }
      rights[i] = j;
      ans = (ans + (int64_t)nums[i] * (i - lefts[i]) * (rights[i] - i)) % MOD;
    } 
    // dump(lefts);
    // dump(rights);
    return (int)ans;
  }
};

// 111ms 70.36% 40.9MB 79.13%
// mono stack
// O(N) O(N)
class Solution {
public:
  int sumSubarrayMins(vector<int>& nums) {
    int n = nums.size(), ans = 0, MOD = 1000000007;
    vector<int> C(n+1);
    stack<int> stck;
    stck.push(-1);
    for (int i = 0; i < n; ++i) {
      while (stck.top() >= 0 && nums[i] <= nums[stck.top()]) {
        stck.pop();
      }
      int j = stck.top();
      C[i + 1] = (C[j + 1] + nums[i] * (i - j)) % MOD;
      stck.push(i);
      ans = (ans + C[i + 1]) % MOD;
    }
    return ans;
  }
};

int main() {
  return 0;
}
