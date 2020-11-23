/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


// // Time Limit Exceeded
// // linear traversal
// // O(HW) O(HW)
// class Solution {
//  public:
//   vector<int> findDiagonalOrder(vector<vector<int>>& M) {
//     vector<int> ans;
//     int h = M.size(), w = M[0].size();
//     for (int y = 0; y < h; ++y) {
//       w = max(w, int(M[y].size()));
//     }
//     for (int i = 0; i < h + w - 1; i++) {
//       int y = min(i, h - 1), x = max(0, i - h + 1);
//       for (int ny = y, nx = x; ny >= 0 && nx < w; ny--, nx++) {
//         if (nx >= M[ny].size())
//           continue;
//         ans.push_back(M[ny][nx]);
//       }
//     }
//     return ans;
//   }
// };

//  1  2  3  4  5
//  6  7
//  8
//  9 10 11
// 12 13 14 15 16

// 408ms 89.73% 89.4MB 73.38%
// linear traversal
// O(HW) O(HW)
class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& M) {
    vector<vector<int>> C;
    vector<int> ans;
    for (int y = 0; y < M.size(); ++y) {
      for (int x = 0; x < M[y].size(); ++x) {
        if (C.size() <= y + x) {
          C.push_back({M[y][x]});
        } else {
          C[y+x].push_back(M[y][x]);
        }
      }
    }
    for (int y = 0; y < C.size(); ++y) {
      for (int x = C[y].size() - 1; x >= 0; --x) {
        ans.push_back(C[y][x]);
      }
    }
    return ans;
  }
};
