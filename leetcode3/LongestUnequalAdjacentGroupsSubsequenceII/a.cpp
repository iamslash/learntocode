/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

using namespace std;

//      n: 3
//           i
//  words: bab dab cab
//                   j
// groups: 1 2 2
//    len: 2 1 1 1 1
//   next: 1 - - - -
//    beg: 0
// maxLen: 2

// 97ms 89.18% 33.6MB 33.73%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
private:
  bool check(vector<string>& words, vector<int>& groups, int i, int j) {
    if (groups[i] == groups[j] || words[i].size() != words[j].size()) {
      return false;
    }
    int diff = 0, n = words[i].size();
    for (int k = 0; k < n; ++k) {
      if (words[i][k] != words[j][k]) {
        if (diff++ > 1) {
          return false;
        }
      }
    }
    return diff == 1;
  }
public:
  vector<string> getWordsInLongestSubsequence(int n,
                                              vector<string>& words,
                                              vector<int>& groups) {
    vector<int> subseqLen(1001, 1), nextIdxs(1001, -1);
    int startIdxMaxLen = -1, maxLen = 0;
    vector<string> ans;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        if (subseqLen[i] < subseqLen[j] + 1 && check(words, groups, i, j)) {
          subseqLen[i] = subseqLen[j] + 1;
          nextIdxs[i] = j;
        }
      }
      if (maxLen < subseqLen[i]) {
        maxLen = subseqLen[i];
        startIdxMaxLen = i;
      }      
    }
    int i = startIdxMaxLen;
    while (i != -1) {
      ans.push_back(words[i]);
      i = nextIdxs[i];
    }
    return ans;
  }
};

int main() {
  return 0;
}
