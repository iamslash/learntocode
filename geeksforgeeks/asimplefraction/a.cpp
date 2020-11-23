// Copyright (C) 2016 by iamslash
// http://www.practice.geeksforgeeks.org/problem-page.php?pid=514

#include <iostream>
#include <cstdint>
#include <string>
#include <map>
#include <cstdlib>
#include <cstdio>

int N, D;

std::string ToString(int n) {
  char buf[128] = {0, };
  snprintf(buf, sizeof(buf), "%d", n);
  return std::string(buf);
}

//
std::string Solve(int n, int d) {
  std::string r;

  std::map<int, int> m;
  m.clear();

  int rem = n % d;

  while ((rem != 0) && (m.find(rem) == m.end())) {
    m[rem] = r.length();

    rem = rem * 10;

    int res_part = rem / d;
    r += ToString(res_part);

    rem = rem % d;
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &D);
    std::cout << Solve(N, D) << std::endl;
  }
  return 0;
}
