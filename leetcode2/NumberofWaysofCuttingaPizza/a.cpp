/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// C[y][x][k] =
//   sum(C[i][x][k-1]) (i=[y+1..h), G[y][x]-G[i][x] > 0) +
//   sum(C[y][j][k-1]) (j=[x+1..w), G[y][x]-G[y][j] > 0)

void print_vv(vector<vector<int64_t>> &VV) {
  for (auto& v : VV) {
    for (auto a : v) {
      printf("%lld ", a);
    }
    printf("\n");
  }
}

// 44ms 34.38% 8.9MB 18.59%
#define MOD 1000000007
class Solution {
 private:
  int64_t dfs(vector<vector<vector<int64_t>>> &C,
              vector<vector<int64_t>> &G,
              int y, int x, int k) {
    int h = G.size() - 1, w = G[0].size() - 1;
    // base
    if (k == 0) {
      if (G[y][x] > 0)
        return 1;
      return 0;
    }
    // memo
    int64_t &r = C[y][x][k];
    if (r >= 0)
      return r;
    // recursion
    r = 0;
    // cut horizontally
    for (int i = y + 1; i < h; ++i) {
      if (G[y][x] - G[i][x] > 0 && G[i][x] >= k) {
        r = (r + dfs(C, G, i, x, k-1)) % MOD;
      }
    }
    // cur vertically
    for (int j = x + 1; j < w; ++j) {
      if (G[y][x] - G[y][j] > 0 && G[y][j] >= k) {
        r = (r + dfs(C, G, y, j, k-1)) % MOD;
      }
    }
    return r;
  }
 public:
  int ways(vector<string>& P, int k) {
    int h = P.size(), w = P[0].size();
    vector<vector<int64_t>> G(h+1, vector<int64_t>(w+1, 0));
    for (int y = h-1; y >= 0; --y) {
      for (int x = w-1; x >= 0; --x) {
        G[y][x] = G[y][x+1];
        for (int z = y; z < h; ++z)
          G[y][x] += (P[z][x] == 'A');
      }
    }
    // print_vv(G);
    vector<vector<vector<int64_t>>> C(
        h+1, vector<vector<int64_t>>(
            w+1, vector<int64_t>(k+1, -1)));
    return dfs(C, G, 0, 0, k-1);
  }
};

int main() {
  vector<string> P = {"A..","AAA","..."};
  int k = 3;
  Solution sln;
  sln.ways(P, k);
}
