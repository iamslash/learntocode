/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <regex>
#include <algorithm>
#include <functional>

// 12ms 10.50% 11.1MB 7.62%
// O(N) O(1)
class Solution {
 private:
  std::vector<std::string> m_country = {"", "+*-", "+**-", "+***-"};
 public:
  std::string maskPII(std::string s) {
    std::string r;
    int i = s.find("@");
    // email
    if (i != std::string::npos) {
      std::transform(s.begin(), s.end(), s.begin(), ::tolower);
      return s.substr(0, 1) + "*****" + s.substr(i-1);
    }
    // phone, remove not digits
    s = std::regex_replace(s, std::regex("[^0-9]"), "");
    int n = s.size();
    return m_country[n-10] + "***-***-" + s.substr(n-4);
  }
};

int main() {
  
  return 0;
}
