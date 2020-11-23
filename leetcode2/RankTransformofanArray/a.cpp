/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// hash map, set
// O(HW) O(HW)
class Solution {
 public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& M) {
    int h = M.size(), w = M[0].size();
    set<int> numSet;
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        numSet.insert(M[y][x]);
      }
    }
    unordered_map<int, int> num2ordMap;
    int i = 0;
    for (int num : numSet) {
      num2ordMap[num] = ++i;
    }
    for (int y = 0; y < h; ++y) {
      for (int x = 0; x < w; ++x) {
        M[y][x] = num2ordMap[M[y][x]];
      }
    }
    return M;
  }
};
