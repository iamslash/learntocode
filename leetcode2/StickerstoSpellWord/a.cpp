/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

//     stickers: with example science
//       target: thehat
// stickerFreqs: i h t w    a e l m p x    c e i n s
//               1 1 1 1    1 2 1 1 1 1    2 2 1 1 1
//   targetFreq: a e h t
//               1 1 2 2

// 68ms 93.97% 12.3MB 48.23%
// dynamic programming
// O(2^T*S*T) O(2^T)
class Solution {
  int dfs(unordered_map<string, int>& C,
          vector<vector<int>>& stickerFreqs, string& target) {
    // base
    if (target.empty())
      return 0;
    // memo
    if (C.count(target))
      return C[target];
    // recursion
    int ans = INT_MAX, n = stickerFreqs.size();
    vector<int> targetFreq(26, 0);
    for (char  c : target)
      targetFreq[c-'a']++;
    for (int i = 0; i < n; ++i) {
      if (stickerFreqs[i][target[0]-'a'] == 0)
        continue;
      string s;
      for (int j = 0; j < 26; ++j) {
        if (targetFreq[j] - stickerFreqs[i][j] > 0) {
          s += string(targetFreq[j] - stickerFreqs[i][j], 'a' + j);
        }
      }
      int tmp = dfs(C, stickerFreqs, s);
      if (tmp != -1) {
        ans = min(ans, 1 + tmp);
      }        
    }
    C[target] = ans == INT_MAX? -1 : ans;
    return C[target];
  }
 public:
  int minStickers(vector<string>& stickers, string target) {
    int n = stickers.size();
    vector<vector<int>> stickerFreqs(n, vector<int>(26, 0));
    unordered_map<string, int> C;
    for (int i = 0; i < n; ++i) {
      for (char c : stickers[i]) {
        stickerFreqs[i][c-'a']++;
      }
    }
    return dfs(C, stickerFreqs, target);
  }
};
