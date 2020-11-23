/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <queue>

// // 192ms 81.46% 40.6MB 62.36%
// // binary search
// // O(WwlgS) O(1)
// class Solution {
//  public:
//   int numMatchingSubseq(std::string s, std::vector<std::string>& W) {
//     std::vector<std::vector<int>> A(26);
//     for (int i = 0; i < s.size(); ++i)
//       A[s[i]-'a'].push_back(i);
//     int cnt = 0;
//     for (auto& w : W) {
//       int last = -1, j = 0;
//       while (j < w.size()) {
//         auto& B = A[w[j]-'a'];
//         auto it = std::upper_bound(B.begin(), B.end(), last);
//         if (it == B.end())
//           break;
//         last = *it;
//         ++j;
//       }
//       if (j == w.size())
//         ++cnt;
//     }
//     return cnt;
//   }
// };

//         i
//      s: a b c d e
//      W: a bb acd ace
//         
// curidx: 1 0 1 0
//         a b c d e
// nxtidx: 0 1 2
//         2
//         3

// 140ms 99.23% 30.3MB 84.87%
// using queue
// O(SW) O(W)
class Solution {
 public:
  int numMatchingSubseq(std::string s, std::vector<std::string>& W) {
    int n = W.size();
    std::vector<int> wi_idx(n, 0);
    std::vector<std::queue<int>> w_idx_q(26);
    for (int i = 0; i < n; ++i)
      w_idx_q[W[i][0]-'a'].push(i);
    for (const auto& c : s) {
      auto& q = w_idx_q[c-'a'];
      int nq = q.size();
      while (nq-- > 0) {
        int i = q.front(); q.pop();
        int j = ++wi_idx[i];
        // printf("c:%c i:%d j:%d\n", c, i, j);
        if (j < W[i].size())
          w_idx_q[W[i][j]-'a'].push(i);
      }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (wi_idx[i] == W[i].size())
        ++cnt;
    }
    return cnt;
  }
};

int main() {
  std::string s = "abcde";
  std::vector<std::string> W = {"a","bb","acd","ace"};
  Solution sln;
  printf("%d\n", sln.numMatchingSubseq(s, W));
  
  return 0;
}
