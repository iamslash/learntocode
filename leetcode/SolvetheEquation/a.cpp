/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 4ms 100.00%
// 4.7MB 0.00%
// use two index i, j
// O(N) O(1)
class Solution {
 public:
  std::string solveEquation(std::string s) {
    // ax + b = cx + d
    // (a-c)x = d-b
    // x = (d-b) / (a-c)
    int a = 0, b = 0;
    int i = 0, j = 0;
    int n = s.size();
    int sign = 1;
    for (int j = 0; j < n; ++j) {

      if (s[j] == '+' || s[j] == '-') {
        if (j > i)
          b += sign * std::stoi(s.substr(i, j-i));
        i = j;
      } else if (s[j] == 'x') {
        // first x, +x
        if ((i == j) || s[j-1] == '+')
          a += sign;
        // -x
        else if (s[j-1] == '-')
          a -= sign;
        else
          a += sign * std::stoi(s.substr(i, j-i));
        i = j + 1;
      } else if (s[j] == '=') {
        if (j > i)
          b += sign * std::stoi(s.substr(i, j-i));
        sign = -1;
        i = j + 1;
      }
    }

    if (i < n)
      b += sign * std::stoi(s.substr(i));
    if (a == 0 && b == 0)
      return "Infinite solutions";
    if (a == 0 && b != 0)
      return "No solution";
    return "x=" + std::to_string(-b/a);
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.solveEquation("x+5-3+x=6+x-2").c_str());
  printf("%s\n", sln.solveEquation("x=x").c_str());
  printf("%s\n", sln.solveEquation("2x=x").c_str());
  printf("%s\n", sln.solveEquation("2x+3x-6x=x+2").c_str());
  printf("%s\n", sln.solveEquation("x=x+2").c_str());
  
  return 0;
}
