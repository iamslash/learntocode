/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>

void printv(std::vector<int> V) {
  for (int i : V)
    printf("%d ", i);
  printf("\n");
}

// // 228ms 47.77% 38.8MB 100.00%
// // O(RC) O(R)
// class Solution {
//  private:
//   std::vector<int> getInverted(std::vector<int> &V) {
//     std::vector<int> I(V.size());
//     std::transform(V.begin(), V.end(), I.begin(), [](int i) {return 1-i;});
//     return I;
//   }
//  public:
//   int maxEqualRowsAfterFlips(std::vector<std::vector<int>>& M) {
//     int h = M.size(), w = M[0].size(), ans = 0;
//     std::map<std::vector<int>, int> ump;
//     for (int y = 0; y < h; ++y) {
//       ump[M[y]]++;
//     }
//     for (int y = 0; y < h; ++y)
//       ans = std::max(ans, ump[M[y]] + ump[getInverted(M[y])]);
//     return ans;
//   }
// };

// 180ms 84.93% 35.2MB 100.00%
// O(HW) O(HW)
class Solution {
 public:
  int maxEqualRowsAfterFlips(std::vector<std::vector<int>> &M) {
    std::unordered_map<std::string, int> ump;
    for (auto &line: M) {
      std::string s;
      int lmb = line[0];
      for (int i = 0; i < line.size(); ++i) {
        s += line[i] == lmb ? '1' : '0';
      }
      ump[s]++;
    }
    int ans = 0;
    for (auto &pr : ump) {
      ans = std::max(ans, pr.second);
    }
    return ans;
  }
};

int main() {

  std::vector<std::vector<int>> M = {
    {0, 1},
    {1, 1}
  };

  Solution sln;
  printf("%d\n", sln.maxEqualRowsAfterFlips(M));
  
  return 0;
}
