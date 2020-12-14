/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 1512ms 7.27% 156.7MB 6.92%
// greedy algorithm, sort
// O(NlgN) O(N)
class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues,
                  vector<int>& bobValues) {
    int n = aliceValues.size();
    vector<vector<int>> C;
    int ans[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
      C.push_back(
          {
            -aliceValues[i]-bobValues[i],
            aliceValues[i],
            bobValues[i]
          });
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < n; ++i) {
      ans[i % 2] += C[i][i % 2 + 1];
    }
    if (ans[0] == ans[1]) {
      return 0;
    }
    return ans[0] > ans[1] ? 1 : -1;
  }
};

// 304ms 99.42% 112.2MB 61.71%
// greedy algorithm
// O(N) O(1)
class Solution {
 public:
  int stoneGameVI(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<vector<int>> idxs(201);
    for (int i = 0; i < n; ++i) {
      idxs[A[i] + B[i]].push_back(i);
    }
    bool aliceTurn = true;
    int alicePt = 0, bobPt = 0;
    for (int sum = 200; sum >= 0; --sum) {
      for (int idx : idxs[sum]) {
        if (aliceTurn) {
          alicePt += A[idx];
        } else {
          bobPt += B[idx];
        }
        aliceTurn = !aliceTurn;
      }                                
    }
    return alicePt == bobPt ? 0 : alicePt > bobPt ? 1 : -1;
  }
};
