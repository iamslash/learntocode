/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

//            i
//   A: 2 2 1 1
//   S: 6 4 5 5
//      j
//   C: 61011
// ans: 6

//              i
//   A: 5 4 3 3 1
//   S: 2 9 8 8 2
//          j
//   C: 2 91025 
// ans: 2 9

using namespace std;

// 156ms 95.97% 20.2MB 5.18%
// dynamic programming
// O(N^2) O(N)
class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int n = scores.size();
    vector<pair<int, int>> scoreAges;
    for (int i = 0; i < n; ++i) {
      scoreAges.push_back({ages[i], scores[i]});
    }
    sort(scoreAges.begin(), scoreAges.end(), greater<pair<int, int>>());
    vector<int> C(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int score = scoreAges[i].second;
      C[i] = score;
      for (int j = 0; j < i; ++j) {
        if (scoreAges[j].second >= score) {
          C[i] = max(C[i], C[j] + score);
        }
      }
      ans = max(ans, C[i]);
    }
    return ans;
  }
};
