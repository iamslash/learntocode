/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// // 284ms 6.90% 223.4MB 100.00%
// // O(N^2) O(N^2)
// class Solution {
//  public:
//   std::string splitLoopedString(std::vector<std::string>& V) {
//     std::vector<std::vector<std::string>> VV;
//     std::string rslt;
//     int n = V.size();
//     for (auto& s : V) {
//       std::string r = s;
//       std::reverse(r.begin(), r.end());
//       if (s.compare(r) < 0)
//         VV.push_back({r, s});
//       else
//         VV.push_back({s, r});
//     }

//     for (int i = 0; i < n; ++i) {
//       for (int j = 0; j < 2; ++j) {
//         std::string s = VV[i][j];
//         for (int k = 0; k < s.size(); ++k) {
//           //
//           std::string t = s.substr(k);
//           for (int l = i+1; l < n; ++l)
//             t += VV[l][0];
//           for (int l = 0; l < i; ++l)
//             t += VV[l][0];
//           t += s.substr(0, k);

//           // printf("[%2d %2d %2d] '%9s' '%9s'\n", i, j, k, rslt.c_str(), t.c_str());
//           if (t.compare(rslt) > 0)
//             rslt = t;
//         }
//       }
//     }
//     return rslt;
//   }
// };

// 36ms 100.00% 61.2MB 100.00%
// optimized
// O(NS) O(NS)
// N: count of V
// S: count of V[i]
class Solution {
 public:
  std::string splitLoopedString(std::vector<std::string>& V) {
    if (V.empty())
      return "";
    int n = V.size();
    // original best string
    std::string alpha;
    for (auto& s : V) {
      std::string t = s;
      std::reverse(t.begin(), t.end());
      alpha += std::max(s, t);
    }
    std::string best = alpha;
    int beg = 0;
    int end = 0;
    for (int i = 0; i < n; ++i) {
      std::string s = V[i];
      std::string t = V[i];
      reverse(t.begin(), t.end());
      end += t.size();
      std::string mid = alpha.substr(end) + alpha.substr(0, beg);
      for (int j = 0; j < t.size(); ++j) {
        if (s[j] >= best[0]) {
          best = std::max(best, s.substr(j) + mid + s.substr(0, j));
        }
        if (t[j] >= best[0])
          best = std::max(best, t.substr(j) + mid + t.substr(0, j));
      }
      beg += t.size();
    }
    return best;
  }
};

int main() {
  std::vector<std::string> V = {"abc", "xyz"};
  // std::vector<std::string> V = {"lc", "evol", "cdy"};
  Solution sln;
  printf("%s\n", sln.splitLoopedString(V).c_str());
  
  return 0;
}
