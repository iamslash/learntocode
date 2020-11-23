/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

//
// 8ms 13.79% 8.8MB 36.36%
// O(N) O(1)
class Solution {
 private:
  double digest(std::string s) {
    int i = s.find("(");
    if (i != std::string::npos) {
      std::string bas = s.substr(0, i);
      std::string rep = s.substr(i+1, s.size()-i-2);
      for (int j = 0; j < 20; ++j)
        bas += rep;
      return std::stod(bas);
    }
    return std::stod(s);
  }
 public:
  bool isRationalEqual(std::string S, std::string T) {
    return digest(S) == digest(T);
  }
};

int main() {

  // std::string S = "0.(52)";
  // std::string T = "0.5(25)";
  // std::string S = "0.1666(6)";
  // std::string T = "0.166(66)";
  std::string S = "0.9(9)";
  std::string T = "1.";

  Solution sln;
  printf("%s\n", sln.isRationalEqual(S, T) ? "true" : "false");
  
  return 0;
}
