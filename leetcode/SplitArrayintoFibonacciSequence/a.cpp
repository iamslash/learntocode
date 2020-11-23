/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 4ms 89.28% 8.6MB 78.66%
// backtracking
// O(N^2) O(N)
class Solution {
 private:
  std::vector<int> m_rslt;
  bool dfs(std::string& s, int i) {
    // base
    if (i == s.size() && m_rslt.size() >= 3) {
      return true;
    }

    // recursion
    for (int j = i; j < s.size() && j-i < 10; ++j) {
      // no first zero from 2 digits
      if (s[i] == '0' && j > i)
        break;
      int64_t num = std::stoll(s.substr(i, j-i+1));
      if (num > INT_MAX)
        break;
      int n = m_rslt.size();
      if (n >= 2 && num > (int64_t)m_rslt[n-1] + (int64_t)m_rslt[n-2])
        break;
      if (n <= 1 || num == (int64_t)m_rslt[n-1] + (int64_t)m_rslt[n-2]) {
        m_rslt.push_back(num);
        if (dfs(s, j+1))
          return true;
        m_rslt.pop_back();
      }
    }

    return false;
  }
 public:
  std::vector<int> splitIntoFibonacci(std::string s) {
    dfs(s, 0);
    return m_rslt;
  }
};

int main() {
  // std::string s = "123456579";
  // std::string s = "11235813";
  // std::string s = "112358130";
  std::string s = "0123";
  
  Solution sln;
  auto rslt = sln.splitIntoFibonacci(s);
  for (int a : rslt)
    printf("%d\n", a);
  
  return 0;
}
