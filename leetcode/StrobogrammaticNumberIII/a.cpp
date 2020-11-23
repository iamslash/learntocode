/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>

// 52ms 62.58% 8.3MB 88.24%
class Solution {
 private:
  int m_cnt = 0;
 private:
  std::unordered_map<char, char> m_P = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
  void dfs(std::string lo, std::string hi,
           std::string s,
           int left, int right) {
    // base
    if (left > right) {
      if ((s.size() == lo.size() && s.compare(lo) < 0) ||
          (s.size() == hi.size() && s.compare(hi) > 0))
        return;
      m_cnt++;
      return;
    }

    // recursion
    for (auto& P : m_P) {
      s[left]  = P.first;
      s[right] = P.second;
      if (s.size() != 1 && s[0] == '0')
        continue;
      if (left < right ||
          left == right && P.first == P.second)
        dfs(lo, hi, s, left + 1, right - 1);
    }
  }
 public:
  int strobogrammaticInRange(std::string lo, std::string hi) {
    for (int len = lo.size(); len <= hi.size(); ++len) {      
      dfs(lo, hi,
          std::string(len, '0'),
          0, len-1);
    }
    return m_cnt;
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.strobogrammaticInRange("50", "100"));
  
  return 0;
}
