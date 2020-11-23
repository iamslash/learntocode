// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/LOAN

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>

using namespace std;

double N;
int M;
double P;

// amount원을 연 이율 rates퍼센트로 duration월간
// 한달에 monthly_payment로 남았을때 대출잔금은?
double balance(double amount, int duration, double rates,
               double monthly_payment) {
  double balance = amount;
  for (int i = 0; i < duration; i++) {
    balance *= (1.0 + (rates / 12.0) / 100.0);
    balance -= monthly_payment;
  }
  return balance;
}

// amount원을 연 이율 rates퍼센트로 duration월 간 가으려면
// 한달에 얼마씩 갚아야 하는가?
double payment(double amount, int duration, double rates) {
  double lo = 0;
  double hi = amount * (1.0 + (rates / 12.0) / 100.0);
  for (int i=0; i < 100; i++) {
    double mid = (lo + hi) / 2.0;
    if (balance(amount, duration, rates, mid) <= 0)
      hi = mid;
    else
      lo = mid;
  }
  return hi;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%lf", &N);
    scanf("%n", &M);
    scanf("%lf", &P);

    printf("%0.10lf\n", payment(N, M, P));
  }

  return 0;
}
