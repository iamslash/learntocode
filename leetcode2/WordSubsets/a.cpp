/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 208ms 68.59% 83.2MB 67.82%
// O(N^2) O(1)
class Solution {
 private:
  std::vector<int> getCnt(std::string& s) {
    std::vector<int> rslt(26);
    for (char c : s) {
      rslt[c-'a']++;
    }
    return rslt;
  }
 public:
  std::vector<std::string> wordSubsets(
      std::vector<std::string>& A,
      std::vector<std::string>& B) {
    std::vector<int> bmax(26);
    for (auto& s : B) {
      auto bcnt = getCnt(s);
      for (int i = 0; i < 26; ++i)
        bmax[i] = std::max(bmax[i], bcnt[i]);
    }
    std::vector<std::string> ans;
    for (auto& s : A) {
      auto acnt = getCnt(s);
      int i;
      for (i = 0; i < 26; ++i)
        if (acnt[i] < bmax[i])
          break;
      if (i == 26)
        ans.push_back(s);
    }
    return ans;
  }
};

int main() {
  return 0;
}
