/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

//   s: "abcd"
// idx: 0 2
// src:   "a"   "cd"
// dst: "eee" "ffff"

// 8ms 74.02% 12.7MB 9.36%
// O(NlgN) O(N)
class Solution {
 public:
  std::string findReplaceString(
      std::string s,
      std::vector<int>& idx,
      std::vector<std::string>& src,
      std::vector<std::string>& dst) {
    int n = idx.size();
    std::vector<std::pair<int, int>> idxdsc;
    for (int i = 0; i < n; ++i)
      idxdsc.push_back({idx[i], i});
    std::sort(idxdsc.rbegin(), idxdsc.rend());
    for (auto& pr : idxdsc) {
      int i = pr.first;
      std::string a = src[pr.second];
      std::string b = dst[pr.second];
      if (s.substr(i, a.size()) == a)
        s = s.substr(0, i) + b + s.substr(i+a.size());
    }
    return s;
  }
};

int main() {
  return 0;
}
