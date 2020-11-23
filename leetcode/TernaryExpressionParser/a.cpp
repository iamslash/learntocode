/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// T?T?2:3:4
// 

// 8ms 100.00% 10.5MB 18.75%
// O(N) O(N)
class Solution {
 private:
  int m_i = 0;
  std::string solve(std::string& s) {
    // base
    if (m_i + 1 >= s.size() || s[m_i+1] != '?')
      return s.substr(m_i, 1);

    // recursion
    char c = s[m_i];
    m_i += 2;
    std::string a = solve(s);
    m_i += 2;
    std::string b = solve(s);
    return c == 'T' ? a : b;
  }
 public:
  std::string parseTernary(std::string s) {
    return solve(s);
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.parseTernary("T?T:F?T?1:2:F?3:4").c_str());
  
  return 0;
}
