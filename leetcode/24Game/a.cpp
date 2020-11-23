/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

// 4ms 100.00% 8.6MB 86.67%
// backtracking
class Solution {
 private:
  bool solve(double a, double b, double c, double d) {
    if (solve(a+b, c, d) || solve(a-b, c, d) || solve(a*b, c, d) || solve(a/b, c, d))
      return true;
    if (solve(a, b+c, d) || solve(a, b-c, d) || solve(a, b*c, d) || solve(a, b/c, d))
      return true;
    if (solve(a, b, c+d) || solve(a, b, c-d) || solve(a, b, c*d) || solve(a, b, c/d))
      return true;
    return false;
  }
  bool solve(double a, double b, double c) {
    if (solve(a+b, c) || solve(a-b, c) || solve(a*b, c) || (b&&solve(a/b, c)))
      return true;
    if (solve(a, b+c) || solve(a, b-c) || solve(a, b*c) || (c&&solve(a, b/c)))
      return true;
    return false;
  }
  bool solve(double a, double b) {
    // printf("%lf %lf\n", a, b);
    if (std::fabs(a+b-24.0) < 1e-6 ||
        std::fabs(a-b-24.0) < 1e-6 ||
        std::fabs(a*b-24.0) < 1e-6 ||
        (b&&std::fabs(a/b-24.0) < 1e-6))
      return true;
    return false;        
  }
 public:
  bool judgePoint24(std::vector<int>& V) {
    std::sort(V.begin(), V.end());
    do {
      if (solve(V[0], V[1], V[2], V[3]))
        return true;
    } while (std::next_permutation(V.begin(), V.end()));
    return false;
  }
};

int main() {
  // std::vector<int> V = {4, 1, 8, 7};
  // std::vector<int> V = {1, 2, 1, 2};
  std::vector<int> V = {1, 1, 1, 1};
  Solution sln;
  printf("%s\n", sln.judgePoint24(V) ? "True" : "False");
  
  return 0;
}
