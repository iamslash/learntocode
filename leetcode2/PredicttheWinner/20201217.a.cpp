/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 4ms 67.35% 7.7MB 6.15%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
public:
  bool PredictTheWinner(vector<int>& A) {
    int n = A.size();
    vector<int> C = A;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < n - i; ++j) {
        C[j] = max(A[j] - C[j+1], A[j+i] - C[j]);
      }
    }    
    return C[0] >= 0;
  }
};

// recursive dynamic programming
// O(N^2) O(N^2)
class Solution {
 public:
  bool PredictTheWinner(vector<int>& P) {
    if(P.size() % 2 == 0) 
      return true;        
    int n = P.size();
    vector<vector<int>> C(n, vector<int>(n, -1));        
    int sum = accumulate(P.begin(), P.end(), 0);
    int score = dfs(P, C, 0, n-1);
    return 2 * score >= sum;
  }
    
  int dfs(vector<int>& P, vector<vector<int>>& C, int i, int j){
    // base
    if(i > j) 
      return 0;
    // memo
    int& r = C[i][j];
    if(r >= 0) 
      return r;
    // recursion
    int a = P[i] + min(dfs(P, C, i+1, j-1), dfs(P, C, i+2, j));
    int b = P[j] + min(dfs(P, C, i, j-2), dfs(P, C, i+1, j-1));
    r = max(a, b);                        
    return r;
  }
};
