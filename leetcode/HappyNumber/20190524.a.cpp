// Copyright (C) 2018 by iamslash
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/113/math/815/

#include <cstdio>
#include <unordered_set>

class Solution {
public:
  bool isHappy(int n) {
    std::unordered_set<int> s(n);
    int a = n, q = n, r = n;
    while (a > 1) {
      q = a;
      a = 0;
      while (q > 0) {
        r = q % 10;
        q = q / 10;
        a += r*r;
      }
      printf("%d\n", a);
      if (s.emplace(a).second == false) {
        // printf("%lu\n", s.size());
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  // assert(s.isHappy(19) == true);
  // assert(s.isHappy(82) == true);
  // assert(s.isHappy(68) == true);
  // assert(s.isHappy(100) == true);
  printf("%s\n", s.isHappy(39166461) ? "true" : "false");

  return 0;
}
