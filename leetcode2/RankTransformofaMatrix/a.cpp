/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>
#include <map>

using namespace std;

// // 688ms 38.69% 87.8MB 5.08%
// // hash map, set
// // O(HW) O(HW)
// class Solution {
//  private:
//   int find(vector<int>& ds, int i) {
//     if (ds[i] < 0)
//       return i;
//     return ds[i] = find(ds, ds[i]);
//   }
//   void process(vector<vector<int>>& M, vector<pair<int, int>>& crds,
//                vector<int>& rows, vector<int>& cols) {
//     int h = M.size(), w = M[0].size();
//     vector<int> ds = vector<int>(h + w, -1);
//     for (auto& pr : crds) {
//       int y = pr.first, x = pr.second;
//       int py = find(ds, y), px = find(ds, h + x);
//       if (py != px) {
//         ds[py] = min({ds[py], ds[px], -max(rows[y], cols[x]) - 1});
//         ds[px] = py;
//       }
//     }
//     for (auto& pr : crds) {
//       int y = pr.first, x = pr.second;
//       M[y][x] = rows[y] = cols[x] = -ds[find(ds, y)];
//     }
//   }
//  public:
//   vector<vector<int>> matrixRankTransform(vector<vector<int>>& M) {
//     int h = M.size(), w = M[0].size(), lastVal = INT_MIN;
//     vector<array<int, 3>> MM;
//     vector<int> rows(h), cols(w);
//     for (int y = 0; y < h; ++y) {
//       for (int x = 0; x < w; ++x) {
//         MM.push_back({M[y][x], y, x});
//       }
//     }
//     sort(MM.begin(), MM.end(), [](array<int, 3>& a, array<int, 3>& b) {
//                                  return a[0] < b[0]; });
//     vector<pair<int, int>> crds;
//     for (auto& arr : MM) {
//       int val = arr.at(0), y = arr.at(1), x = arr.at(2);
//       if (val != lastVal) {
//         process(M, crds, rows, cols);
//         lastVal = val;
//         crds.clear();
//       }
//       crds.push_back({y, x});
//     }
//     process(M, crds, rows, cols);
//     return M;
//   }
// };

// 2014ms 21.64% 56.8MB 5.08%
class Solution {
 public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& M) {
    int h = M.size(), w = M[0].size();
    vector<pair<int, int>> rows(h, {0, INT_MIN});
    vector<pair<int, int>> cols(w, {0, INT_MIN});        
    map<int, vector<pair<int, int>>> v;
    for (int y = 0; y < h; ++y) 
      for (int x = 0; x < w; ++x) 
        v[M[y][x]].push_back({y, x});
        
    vector<vector<int>> ans (h, vector<int>(w, 0));
    for (auto& pr : v) {
      while (true) {
        bool noChange = true;
        for (auto& u : pr.second) {
          int r = u.first;
          int c = u.second;
          int val = max(pr.first > rows[r].second ?
                        rows[r].first + 1 :
                        rows[r].first, 
                        pr.first > cols[c].second ?
                        cols[c].first + 1 :
                        cols[c].first);                
          if (ans[r][c] != val) {
            ans[r][c] = val;
            noChange = false;
          }                
          rows[r].first = cols[c].first = val;
          rows[r].second = cols[c].second = pr.first;
        }                
        if (noChange)
          break;
        if (pr.second.size() == 1)
          break;
      }
    }        
    return ans;
  }
};
