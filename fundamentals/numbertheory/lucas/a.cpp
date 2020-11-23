// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <algorithm>

// pascal triangle
int nCr_dp(int n, int r, int p) {
  int C[r+1] = {0,};
  C[0] = 1; // top row of pascal triangle
  for (int i = 1; i <= n; ++i) {
    for (int j = std::min(i, r); j > 0; --j) {
      // nCj = (n-1)Cj + (n-1)C(j-1)
      C[j] = (C[j] + C[j-1]) % p;
    }
  }
  return C[r];
}

int nCr_lucas(int n, int r, int p) {
  // base condition
  if (r == 0)
    return 1;

  // recursion
  int ni = n % p;
  int ri = r % p;
  return (nCr_lucas(n/p, r/p, p) *
          nCr_dp(ni, ri, p)) % p;  
}

int mul(int x, int y, int p) {
    int r = 1;
    while (y > 0) {
        if (y%2 != 0) {
            r *= x;
            r %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return r;
}

int power(int x, unsigned int y, int p) {
  int r = 1;
  while (y > 0) {
    if (y & 1) {
      r *= x;
      r %= p;
    }
    y = y >> 1;
    x *= x;
    x %= p;
  }
  return r;
}

int modinv(int n, int p) {
  return power(n, p-2, p);
}

int nCr_ferma(int n, int r, unsigned int p) {
  if (r == 0)
    return 1;
  int fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fac[i] = fac[i-1] * i % p;
  }
  return (fac[n] * modinv(fac[r], p) % p * modinv(fac[n-r], p) % p) % p;
}

int main() {
  int n = 1000;
  int r = 900;
  int p = 13;
  printf("%d\n", nCr_lucas(n, r, 1000000007));
  // printf("%d\n", nCr_ferma(n, r, p));
  // printf("%d\n", mul(3, 5, 7)); // 0x0101
  // printf("%d\n", power(3, 5, 7)); // 0x0101
  
  return 0;
}
