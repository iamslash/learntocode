/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <bitset>

// 252ms 78.06% 63.8MB 100.00%
// bitfield
class Solution {
 public:
  std::vector<bool> canMakePaliQueries(
      std::string s, std::vector<std::vector<int>>& Q) {
    int bm = 0;
    std::vector<int> ps(1);
    std::vector<bool> ans;
    for (char c : s)
      ps.push_back(bm ^= 1 << (c - 'a'));
    for (auto& q : Q) {
      int cnt = __builtin_popcount(ps[q[1]+1] ^ ps[q[0]]);
      ans.push_back(q[2] >= cnt / 2);
    }
    return ans;
  }
};

int main() {
  return 0;
}
