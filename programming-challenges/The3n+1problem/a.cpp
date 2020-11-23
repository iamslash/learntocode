/* Copyright (C) 2016 by iamslash */

#include <iostream>
#include <cstring>

int CACHE[1000000];

int cycle_len(int n) {
  // base condition
  if (n == 1)
    return 1;

  // memoization
  int& r = CACHE[n];
  if (r > 0)
    return r;

  r = 1;  
  // recursion
  if (n % 2 == 0) {
    r += cycle_len(n / 2);
  } else {
    r += cycle_len(n * 3 + 1);
  }
  //
  return r;
}

int main() {
  int I, J;
  // while (std::cin.good()) {
  //   std::cin >> I >> J;
  while(std::cin >> I >> J) {
    memset(CACHE, -1, sizeof(CACHE));
    int m = 0;
    for (int i = I; i <= J; ++i) {
      m = std::max(m, cycle_len(i));
    }
    // printf("%d %d %d\n", I, J, m);
    std::cout << I << " " << J << " " << m << "\n";//std::endl;
  }

  // std::cout << sizeof(CACHE);

  return 0;
}
