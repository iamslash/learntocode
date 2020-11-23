/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

// 8ms 45.70% 8.7MB 100.00%
class Solution {
 private:
  bool pending(const vector<vector<int>>& B) {
    for (int y = 0; y < 3; ++y) {
      for (int x = 0; x < 3; ++x) {
        if (B[y][x] == 0)
          return true;
      }
    }
    return false;
  }
  bool winner(const vector<vector<int>>& B, int n) {
    if ( (B[0][0] == B[0][1] && B[0][1] == B[0][2] && B[0][1] == n) ||
         (B[1][0] == B[1][1] && B[1][1] == B[1][2] && B[1][1] == n) ||
         (B[2][0] == B[2][1] && B[2][1] == B[2][2] && B[2][1] == n) ||
         (B[0][0] == B[1][1] && B[2][2] == B[1][1] && B[1][1] == n) ||
         (B[0][2] == B[1][1] && B[1][1] == B[2][0] && B[1][1] == n) ||
         (B[0][0] == B[1][0] && B[1][0] == B[2][0] && B[0][0] == n) ||
         (B[0][1] == B[1][1] && B[1][1] == B[2][1] && B[1][1] == n) ||
         (B[0][2] == B[1][2] && B[1][2] == B[2][2] && B[2][2] == n))
      return true;
    return false;
  }
 public:
  string tictactoe(vector<vector<int>>& M) {
    vector<vector<int>> B(3, vector<int>(3, 0));
    for (int i = 0; i < M.size(); ++i) {
      int val = 1;
      if (i % 2 > 0)
        val = 2;
      B[M[i][0]][M[i][1]] = val;
    }
    if (winner(B, 1))
      return "A";
    if (winner(B, 2))
      return "B";
    if (pending(B))
      return "Pending";
    return "Draw";
  }
};
