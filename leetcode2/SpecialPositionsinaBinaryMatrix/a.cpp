/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 44ms 100.00% 13.6MB 33.33%
// O(N^2) O(N)
class Solution {
 public:
  int numSpecial(vector<vector<int>>& M) {
    int h = M.size(), w = M[0].size();
    vector<int> rows(h);
    vector<int> cols(w);
    vector<pair<int, int>> cands;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        if (M[y][x] == 1) {
          rows[y]++;
          cols[x]++;
          cands.push_back({y, x});
        }
      }
    }
    int ans = 0;
    for (auto& pr : cands) {
      if (rows[pr.first] == 1 && cols[pr.second])
        ans++;
    }
    return ans;
  }
};
