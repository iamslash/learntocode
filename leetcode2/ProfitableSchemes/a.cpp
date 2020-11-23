/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//      G: 5
//      P: 3
//  group: 2 2
// profit: 2 3

// 136ms 68.52% 9.1MB 69.75%
// iterative dynamic programming
// O(G^2P) O(GP)
#define MOD 1000000007
class Solution {
 public:
  int profitableSchemes(int G, int P,
                        vector<int>& group,
                        vector<int>& profit) {
    vector<vector<int>> C(G + 1, vector<int>(P + 1, 0));
    C[0][0] = 1;
    int ans = 0;
    for (int k = 0; k < group.size(); ++k) {
      int g = group[k];
      int p = profit[k];
      for (int i = G; i >= g; --i) {
        for (int j = P; j >= 0; --j) {
          C[i][j] = (C[i][j] + C[i-g][max(0, j - p)]) % MOD;
        }
      }
    }
    for (int i = 0; i <= G; ++i) {
      ans = (ans + C[i][P]) % MOD;
    }
    return ans;
  }
};
