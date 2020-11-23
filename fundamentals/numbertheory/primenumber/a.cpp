// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>

bool IsPrime(int n) {
  if (n <= 1)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  int sqrtn = sqrt(n);
  for (int i = 3; i <= sqrtn; i += 2) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  printf("%d\n", IsPrime(3));
  printf("%d\n", IsPrime(33));
  return 0;
}
