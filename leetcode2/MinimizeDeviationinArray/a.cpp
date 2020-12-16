/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

// nums: 1 2 3 4
//  ans:            3
//
//       2 2 4 6
//       2 2 3 4    2
//       2 2 2 3    1

// nums: 4 1 5 20 3    ans
//
//       1 3 4 5 20    
//       2 4 6 10 20   18
//       2 4 6 10 10   8
//       2 4 5  6 10   8
//       2 4 5  5  6   4
//       2 3 4  5  5   3

// 900ms 21.47% 121.7MB 34.53%
// priority queue
// O(NlgN) O(N)
class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    set<int> numSet;
    for (int num : nums) {
      numSet.insert(num % 2 > 0 ? num * 2 : num);
    }
    int ans = *numSet.rbegin() - *numSet.begin();
    while (*numSet.rbegin() % 2 == 0) {
      numSet.insert(*numSet.rbegin() / 2);
      numSet.erase(*numSet.rbegin());
      ans = min(ans, *numSet.rbegin() - *numSet.begin());
    }
    return ans;
  }
};

