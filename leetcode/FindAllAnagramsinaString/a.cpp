/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 32ms 77.33% 10.3MB 88.46%
// sliding window
// O(N) O(1)
class Solution {
 public:
  std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> sv(26, 0), pv(26, 0), ans;
    int m = s.size(), n = p.size();
    if (m < n)
      return ans;
    for (int i = 0; i < n; ++i) {
      ++pv[p[i]-'a'];
      ++sv[s[i]-'a'];
    }
    if (pv == sv)
      ans.push_back(0);
    for (int i = n; i < m; ++i) {
      ++sv[s[i  ]-'a'];
      --sv[s[i-n]-'a'];
      if (pv == sv)
        ans.push_back(i - n + 1);
    }
    return ans;
  }
};

int main() {
  return 0;
}
