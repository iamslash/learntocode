/* Copyright (C) 2021 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

//  A[0]: 101  
// first: 001
//        100
// first: 001
//        101
//
// a ^ b ^ a = b

// encoded: [0]^[1]     [1]^[2]     [2]^[3]
// ans: [0] [0]^[1]^[0] [1]^[2]^[1] [2]^[3]^[2]
// 

// 92ms 60.00% 25.3MB 80.00%
// brute force
// O(N) O(N)
class Solution {
 public:
  vector<int> decode(vector<int>& encoded, int first) {
    int n = encoded.size() + 1;
    vector<int> ans(n);
    ans[0] = first;
    copy(encoded.begin(), encoded.end(), ans.begin()+1);
    for (int i = 1; i < n; ++i) {
      ans[i] = ans[i] ^ ans[i-1];
    }
    return ans;
  }
};
