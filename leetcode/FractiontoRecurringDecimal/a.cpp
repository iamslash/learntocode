/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/821/

#include <cstdio>
#include <string>
#include <unordered_map>

class Solution {
 public:
  std::string fractionToDecimal(int64_t n, int64_t d) {
    std::string rslt;

    // check zero n
    if (n == 0)
      return "0";

    // check sign
    if (n < 0 ^ d < 0)
      rslt += "-";

    // remove sign of operands
    n = std::abs(n);
    d = std::abs(d);

    // get integer part
    rslt += std::to_string(n / d);

    // check 0 fractional part
    if (n % d == 0)
      return rslt;

    // int a = 2, b = 3;
    rslt += '.';
    std::unordered_map<int, int> um;

    // loop remain
    for (int64_t r = n % d; r; r %= d) {
      if (um.count(r) > 0) {
        rslt.insert(um[r], 1, '(');
        rslt += ')';
        break;
      }
      um[r] = rslt.size();
      r *= 10;
      rslt += std::to_string(r / d);
    }

    return rslt;
  }
};

int main() {
  Solution s;
  printf("%s\n", s.fractionToDecimal(1, 3).c_str());
  printf("%s\n", s.fractionToDecimal(1, 2).c_str());

  return 0;
}
