// Copyright (C) 2016 by iamslash

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <vector>

#define MAXN 65535

// min_factor[i] : i를 소인수 분해할때 제일 작은 소수
int min_factor[MAXN];

// sieve of eratosthenes를 이용하여
// 특정 숫자 n까지 순회하면 소인수 분해했을때
// 제일 작은 수를 저장한다.
void Eratosthenes(int n) {
  // init min_factor
  min_factor[0] = min_factor[1] = -1;
  for (int i = 2; i <= n; ++i) {
    min_factor[i] = i;
  }
  //
  int sqrtn = sqrt(n);
  for (int i = 2; i <= sqrtn; ++i) {
    if (min_factor[i] == i) {
      for (int j = i * i; j <= n; j += i) {
        if (min_factor[j] == j)
          min_factor[j] = i;
      }
    }
  }
}

std::vector<int> Factor(int n) {
  std::vector<int> r;

  while (n > 1) {
    r.push_back(min_factor[n]);
    n /= min_factor[n];
  }

  return r;
}

int main() {
  int n = 132;
  Eratosthenes(n);
  std::vector<int> r = Factor(n);
  for (auto it = r.begin(); it != r.end(); ++it) {
    printf("%d ", *it);
  }
  printf("\n");
  return 0;
}
