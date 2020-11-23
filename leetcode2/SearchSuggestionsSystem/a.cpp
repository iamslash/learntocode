/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// 48ms 81.67% 33.1MB 100.00%
// binary search
// O(NlgN) O(N)
class Solution {
 public:
  std::vector<std::vector<std::string>> suggestedProducts(
      std::vector<std::string>& P, std::string S) {
    std::vector<std::vector<std::string>> ans;
    std::string key;
    auto it = P.begin();
    std::sort(it, P.end());
    for (char c : S) {
      ans.push_back(std::vector<std::string>());
      key += c;
      it = std::lower_bound(it, P.end(), key);
      for (int i = 0; i < 3 && it+i != P.end(); i++) {
        std::string& s = *(it + i);
        if (s.find(key))
          break;
        ans.back().push_back(s);
      }
    }
    return ans;
  }
};

int main() {
  return 0;
}
