// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/PASS486

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

int N, LO, HI;

const int TM = 1000*1000*10;
// min_factor[i] = i의 가장 작은 소인수
// i가 소인수인 경우 자기 자신
int min_factor[TM+1];
// min_factor_power[i] = i의 소인수 분해에는
// min_factor의 몇승이 포함되어 있는가?
int min_factor_power[TM+1];
// factor[i] = i아 가진 약수의 수
int factors[TM+1];

bool is_prime[TM+1];
void eratosthenes(int n) {
  memset(is_prime, 1, sizeof(is_prime));

  is_prime[0] = is_prime[1] = false;
  // n 의 약수가 1과 n이라면 소수다.
  // 2부터 n-1까지 n을 나누어보고 나누어지면 n은 소수가 아니다.
  // n을 p * q로 구성할 수 있다면 p의 최대값은 sqrt(n)이다.
  int sqrtn = static_cast<int>(sqrt(n));

  for (int i=2; i <= sqrtn; ++i) {
    if (is_prime[i]) {
      // j는 i*i부터 시작해도 된다. 그 이전의 수는
      // 이미 소수가 아니다.
      for (int j=i*i; j <= n; j+=i) {
        is_prime[j] = false;
      }
    }
  }
}

void eratosthenes2(int n) {
  min_factor[0] = min_factor[1] = -1;

  for (int i=2; i <= n; ++i) {
    min_factor[i] = i;
  }

  int sqrtn = static_cast<int>(sqrt(n));
  for (int i=2; i <= sqrtn; ++i) {
    if (min_factor[i] == i) {
      for (int j=i*i; j <= n; j += i) {
        if (min_factor[j] == j)
          min_factor[j] = i;
      }
    }
  }
}

std::vector<int> factor(int n) {
  std::vector<int> r;

  while (n > 1) {
    r.push_back(min_factor[n]);
    n /= min_factor[n];
  }
  //
  return r;
}

void get_factors_smart() {
  //
  factors[1] = 1;

  //
  for (int n=2; n <= TM; ++n) {
    if (min_factor[n] == n) {
      min_factor_power[n] = 1;
      factors[n] = 2;
    } else {
      int p = min_factor[n];
      int m = n / p;

      if (p != min_factor[m]) {
        min_factor_power[n] = 1;
      } else {
        min_factor_power[n] = min_factor_power[m] + 1;
      }

      int a = min_factor_power[n];
      factors[n] = (factors[m] / a) * (a + 1);
    }
  }
}

int solve() {
  int r = 0;
  //
  for (int i=LO; i <= HI; ++i) {
    if (factors[i] == N)
      ++r;
  }

  return r;
}

int main() {
  int T;  // number of T

  // precalc
  eratosthenes2(TM);
  get_factors_smart();
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    scanf("%d", &LO);
    scanf("%d", &HI);

    printf("%d\n", solve());
  }

  return 0;
}
