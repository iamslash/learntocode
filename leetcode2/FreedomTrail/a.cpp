/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// 588ms 6.72% 164.7MB 5.04%
// dynamic programming
// O(RK) O(RK)
class Solution {
 private:
  int dfs(unordered_map<string, int>& C, string ring, string key, int i) {
    // base
    if (i == key.size())
      return 0;
    // recursion
    char c = key[i];
    string hashkey = ring + to_string(i);
    if (C.count(hashkey))
      return C[hashkey];
    int minstep = INT_MAX;
    for (int j = 0; j < ring.size(); ++j) {
      if (ring[j] == c) {
        string rotated = ring.substr(j) + ring.substr(0, j);
        int step = 1 + min(j, int(rotated.size()) - j) +
            dfs(C, rotated, key, i + 1);
        minstep = min(minstep, step);
      }
    }
    C[hashkey] = minstep;
    return minstep;
  }
 public:
  int findRotateSteps(string ring, string key) {
    unordered_map<string, int> C;
    return dfs(C, ring, key, 0);
  }
};
