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

  // i is until not n but sqrt(n)
  // because any composite number is consisted of p and q (p x q)
  // p <= sqrt(n)
  // q >= sqrt(n)
  int sqrtn = int(sqrt(n));
  for (int i = 2; i <= sqrtn; ++i) {
    if (IsPrime(i)) {
      // j is not from i * 2 
      // because it is watched already
      for (int j = i * i; j <= n; j += i) {
        SetComposite(j);
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
