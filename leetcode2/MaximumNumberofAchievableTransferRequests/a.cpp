/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

//        n: 5
// requests: 0,1 1,0 0,1 1,2 2,0 3,4

// 492ms 46.54 9MB 96.68%
// back tracking
// O(N) O(N)
class Solution {
 private:
  int dfs(vector<int>& C, vector<vector<int>>& reqs, int i) {
    // base    
    if (i == reqs.size()) {
      if (count(C.begin(), C.end(), 0) == C.size())
        return 0;
      return INT_MIN;
    }
    // recursion
    --C[reqs[i][0]];
    ++C[reqs[i][1]];
    int take = 1 + dfs(C, reqs, i+1);
    ++C[reqs[i][0]];
    --C[reqs[i][1]];
    return max(take, dfs(C, reqs, i+1));
  }
 public:
  int maximumRequests(int n, vector<vector<int>>& reqs) {
    // building's balance
    vector<int> C(n);
    return dfs(C, reqs, 0);
  }
};
