/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


//      k: 1
//             i
//   nums: 1 3 1 2 2
//                 j
// cntMap: 1 2 3
//         1 2 0
//    ans: 4

// sliding window, hash map, hash set
// O(N) O(N)
class Solution {
public:
  int countCompleteSubarrays(const vector<int>& nums) {
    unordered_map<int, int> cntMap;
    unordered_set<int> numSet;
    for (int num : nums) {
      numSet.insert(num);
    }
    int n = nums.size(), i = 0, ans = 0, k = numSet.size();
    for (int j = 0; j < n; ++j) {
      if (cntMap[nums[j]]++ == 0) {
        k--;
      }
      while (k == 0) {
        if (--cntMap[nums[i++]] == 0) {
          k++;
        }
      }
      ans += i; 
    }
    return ans;
  }
};

int main() {
  printf("Hello World\n");
}
