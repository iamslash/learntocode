/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// Idea: recursive dynamic programming
// 
//               i
// words: aa ab bc
//
//                     2 + dfs(1, a, a)
//                       /             \
//         2 + dfs(2,a,a)                1 + dfs(2,a,b)
//            /          \                  /          \
//  2 + dfs(3,b,a)  2 + dfs(3,a,c)  2 + dfs(3,b,b)  1 + dfs(3,a,c)
//
// 145ms 84.17% 41.8MB 49.37%
// recursive dynamic programming
// O(N) O(N)
class Solution {
public:
  int C[1001][30][30] = {};
  int dfs(const vector<string>& words, int i, char prevFirst, char prevLast) {
    int n = words.size();
    // base
    if (i >= n) {
      return 0;
    }
    // memo
    if (C[i][prevFirst - 'a'][prevLast - 'a'] > 0) {
      return C[i][prevFirst - 'a'][prevLast - 'a'];
    }
    // recursion
    int m = words[i].size();
    int cnt1 = m + dfs(words, i + 1, words[i][0], prevLast);
    if (words[i].back() == prevFirst) {
      cnt1--;
    }
    int cnt2 = m + dfs(words, i + 1, prevFirst, words[i].back());
    if (words[i][0] == prevLast) {
      cnt2--;
    }
    return C[i][prevFirst - 'a'][prevLast - 'a'] = min(cnt1, cnt2);
  }
  int minimizeConcatenatedLength(vector<string>& words) {
    return words[0].size() + dfs(words, 1, words[0][0], words[0].back());
  }
};

int main() {
  return 0;
}
