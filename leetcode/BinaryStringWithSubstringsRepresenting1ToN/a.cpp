/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <bitset>
#include <string>

// 0ms 100.00% 8.7MB 76.62%
// O(NS) O(N)
class Solution {
 public:
  bool queryString(std::string S, int N) {
    for (int i = 1; i <= N; ++i) {
      std::string b = std::bitset<32>(i).to_string();
      // change 0000...10 to 10.
      b = b.substr(b.find("1"));
      //printf("%s\n", b.c_str());
      if (S.find(b) == std::string::npos)
        return false;
    }
    return true;
  }
};

int main() {
  return 0;
}
