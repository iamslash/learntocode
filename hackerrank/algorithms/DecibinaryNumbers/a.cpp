// Copyright (C) 2018 by iamslash
// https://www.hackerrank.com/challenges/decibinary-numbers/problem

//   0
//   1
//   2
//  10
//   3
//  11
//   4
//  12
//  20
// 100

// 2^60 = 10^18

#include <cstdio>
#include <vector>
#include <string>

#include <iostream>
#include <locale>

// dp[i][j]
// i: digit index
// j: decimal value
//
// pow(2, 25) = 33,554,432
// pow(2, 19) = 524,288
int64_t dp[19][300005];
// ps[i] : partial sum of count for i decimal value 
// i: decimal value
int64_t ps[300000];

// d: digit index (0-24)
// s: decimal value
//
// examples:
//  cnt(0, 7) = 1
int64_t cnt(int d, int decimal) {
  // base condition
  if (decimal == 0 && d == -1) {
    return 1;
  } else if (d == -1) {
    return 0;
  }
  // memoization
  int64_t& r = dp[d][decimal];
  if (r != -1)
    return r;

  // recursion
  r = 0;
  for (int i = 0; i <= 9; ++i) {
    // left most number
    int lmn = (1<<d)*i;
    if (decimal - lmn < 0)
      break;
    r += cnt(d-1, decimal - lmn);
  }
  return r;
}

std::string solve(int64_t x) {
  if (x == 1)
    return "0";
  int64_t ubnd = 0;  // upper bound decimal value
  int64_t lo = 0;
  int64_t hi = 300004;
  // Binary Search for ubnd
  while (lo <= hi) {
    int64_t mid = (lo + hi) / 2;
    if (ps[mid] >= x) {
      ubnd = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  int64_t diff = x - ps[ubnd-1];
  int64_t decimal = ubnd;
  int64_t delta;
  int d;
  // find max digit for s
  for (int i = -1; cnt(i, decimal) < diff; ++i)
    d = i;
  d++;
  // find one digit of decibinary number from the left.
  std::string r;
  while (d >= 0) {
    delta = 0;
    for (int i = 0; i <= 9; ++i) {
      int lmn = (1<<d)*i;
      if ((decimal - lmn) >= 0) {
        delta += cnt(d - 1, decimal - lmn);
      }
      if (delta >= diff) {
        r += std::to_string(i);
        diff -= delta - cnt(d - 1, decimal - lmn);
        decimal -= lmn;
        break;
      }
    }
    d--;
  }
  return r;
}

int main() {
  // printf("%f\n", 1e1);
  // init cache
  for (int i = 0; i < 19; ++i) {
    for (int j = 0; j < 300000; ++j) {
      dp[i][j] = -1;
    }
  }
  ps[0] = cnt(18, 0);
  for (int i = 1; i < 300000; ++i) {
    ps[i] = ps[i-1] + cnt(18, i);
    // if (ps[i] > 11111111111111111)
    //   printf("%10lld : %lld\n", i, ps[i]);
  }
  
  // process
  int Q;
  scanf("%d", &Q);
  for (int q = 0; q < Q; ++q) {
    int64_t x;
    scanf("%lld", &x);
    printf("%s\n", solve(x).c_str());
  }
  return 0;
}
