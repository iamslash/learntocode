/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <bitset>

// 84ms 66.77% 22.3MB 100.00%
// bit manipulation
// O(N^2) O(N)
class Solution {
 public:
  std::vector<int> smallestSufficientTeam(
      std::vector<std::string>& R,
      std::vector<std::vector<std::string>>& P) {
    int n = R.size();
    std::unordered_map<std::string, int> skill2bm;
    std::unordered_map<int, std::vector<int>> bm2people;
    bm2people.reserve(1<<n);
    bm2people[0] = {};
    for (int i = 0; i < n; ++i)
      skill2bm[R[i]] = 1 << i;
    for (int i = 0; i < P.size(); ++i) {
      int curbm = 0;
      for (auto& skill : P[i])
        curbm |= skill2bm[skill];
      // std::bitset<8> bscur(curbm);
      // printf("%s\n", bscur.to_string().c_str());
      for (auto& pr : bm2people) {
        int combm = curbm | pr.first;
        // std::bitset<8> bscom(combm);
        // printf("  %s\n", bscom.to_string().c_str());

        if (bm2people.count(combm) == 0 ||
            bm2people[combm].size() > bm2people[pr.first].size() + 1) {
          bm2people[combm] = pr.second;
          bm2people[combm].push_back(i);
        }
      }
    }
    return bm2people[(1<<n)-1];
  }
};

int main() {
  return 0;
}
