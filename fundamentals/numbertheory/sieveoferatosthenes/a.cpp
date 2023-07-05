// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>

#define MAX_N 987654321

unsigned char SIEVE[(MAX_N + 7) / 8];

// k is prime ???
inline bool IsPrime(int k) {
  return SIEVE[k >> 3] & (1 << (k & 7));
}

// turn off the bit
// k is not prime
inline void SetComposite(int k) {
  SIEVE[k >> 3] &= ~(1 << (k & 7));
}

void PrintSieve(int n) {
  for (int i = 0; i < n; ++i) {
    if (IsPrime(i))
        printf("%d ", i);
  }
  printf("\n");
}

void EratosThenes(int n) {
  memset(SIEVE, 0xFF, sizeof(SIEVE));
  SetComposite(0);
  SetComposite(1);

  // c = p * q (p <= q)
  // p <= sqrt(n)
  // p * p <= n
  int sqrtn = int(sqrt(n));
  for (int p = 2; p <= sqrtn; ++p) {
    if (IsPrime(p)) {
      // c = p * q (p <= q) 
      // q >= sqrt(n)
      for (int c = p * p; c <= n; c += p) {
        SetComposite(c);
      }
    }
  }
  printf("\n");
}

int main()
{
  int n = 1024;
  EratosThenes(n);
  PrintSieve(n);
  return 0;
}
