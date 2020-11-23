// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <vector>

std::vector<int> FactorSimple(int n) {
  std::vector<int> r;
  int sqrtn = sqrt(n);
  // divide n by 2, 3, 5, etc...
  for (int div = 2; div <= sqrtn; ++div) {
    while (n % div == 0) {
      n /= div;
      r.push_back(div);
    }
  }
  if (n > 1)
    r.push_back(n);

  return r;
}

int main() {
  std::vector<int> r = FactorSimple(132);
  for (auto it = r.begin(); it != r.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n");
  return 0;
}
