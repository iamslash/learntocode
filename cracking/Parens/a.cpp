// Copyright (C) 2017 by iamslash

// Parens: Implement an algorithm to print all valid (Le., properly
// opened and closed) combinations of n pairs of parentheses.
//
// EXAMPLE
// Input: 3
// Output: ((())), (()()), (())(), ()(()), ()()()
//
// ()
// ()() (())
// ()()() (())() ()(()) ()(()) (()()) ((()))
//

#include <cstdio>
#include <set>
#include <string>

int N;

std::set<std::string> solve(int n) {
  std::set<std::string> r;
  // base condition
  if (n == 0) {
    r.insert("");
    return r;
  }
  // recursion
  std::set<std::string> prev_set = solve(n - 1);
  for (const std::string& s : prev_set) {
    r.insert("()" + s);
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        std::string s2 = s.substr(0, i+1) + "()" + s.substr(i+1);
        // printf("%d %s\n", n, s2.c_str());
        r.insert(s2);
      }
    }
  }
  return r;
  
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::set<std::string> R = solve(N);
    for (const std::string& s : R) {
      printf("%s\n", s.c_str());
    }
  }
  return 0;
}

