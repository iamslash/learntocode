// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>

#define MAX_N 987654321
unsigned char SIEVE[(MAX_N + 7) / 8];

bool is_prime(const int& n) {
  int div = n / 8;
  int mod = n % 8;
  return (SIEVE[div] & (1 << mod)) ? true : false;;
}

void set_composite(const int& n) {
  int div = n / 8;
  int mod = n % 8;
  SIEVE[div] &= ~(1 << mod);
}

void print_sieve(const int& n) {
  for (int i = 0; i < n; ++i) {
    if (is_prime(i))
      printf("%d ", i);
  }
  printf("\n");
}

void eratos_thenes(const int& n) {
  set_composite(0);
  set_composite(1);

  for (int i = 2; i*i <= n; ++i) {
    if (is_prime(i)) {
      printf("  %d\n", i);
      for (int j = i*i; j < n; j+=i) {
        printf("%d ", j);
        set_composite(j);
      }
      printf("\n");
    }
  }
}

int main() {
  memset(SIEVE, 255, sizeof(SIEVE));
  int N = 64;
  eratos_thenes(N);
  print_sieve(N);
  return 0;
}
