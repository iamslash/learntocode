// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/FANMEETING

// karatsuba
// c = a * b
// c = (a0 + a1 * 10^128) * (b0 + b1 * 10^128)
// c = (a1 * b1)10^256 + (a1 * b0 + b1 * a0)10^128 + (a0 * b0)
// c = z2 * 10^256       + z1 * 10^128             + z0        
//
// (a0 + a1)*(b0 + b1) = a0b0 + (a0b1 + a1b0) + a1b1 
// x                     z0     z1              z2

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

void normalize(std::vector<int>& a) {
  return;
  a.push_back(0);
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] < 0) {
      int borrow = (std::abs(a[i]) + 9) / 10;
      a[i + 1] -= borrow;
      a[i] += borrow * 10;
    } else {
      a[i + 1] += a[i] / 10;
      a[i] %= 10;
    }
  }
  while (a.size() > 1 && a.back() == 0)
    a.pop_back();
}

// a = a + b * 10 ^ k
void add_to(std::vector<int>& a, const std::vector<int>& b, int k) {
  a.resize(std::max<int>(a.size(), b.size() + k));
  for (int i = 0; i < b.size(); ++i) {
    a[i + k] += b[i];
  }
  normalize(a);
}

// a = a - b
// 111 22
void sub_from(std::vector<int>& a, const std::vector<int>& b) {
  a.resize(std::max<int>(a.size(), b.size()) + 1);
  for (int i = 0; i < b.size(); i++) {
    a[i] -= b[i];
  }
  normalize(a);
}

std::vector<int> multiply(const std::vector<int>& a, const std::vector<int>& b) {
  std::vector<int> r(a.size() + b.size() + 1, 0);
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      r[i + j] += a[i] * b[j];
    }
  }
  normalize(r);
  return r;
}

std::vector<int> karatsuba(const std::vector<int>& a,
                           const std::vector<int>& b)
{
  int an = a.size();
  int bn = b.size();
  // base condition
  if (an < bn)
    return karatsuba(b, a);
  // base condition
  if (an == 0 || bn == 0)
    return std::vector<int>();
  // base condition
  if (an <= 50)
    return multiply(a, b);

  int half = an / 2;
  std::vector<int> a0(a.begin(), a.begin() + half);
  std::vector<int> a1(a.begin() + half, a.end());
  std::vector<int> b0(b.begin(), b.begin() +
                      std::min<int>(b.size(), half));
  std::vector<int> b1(b.begin() + std::min<int>(b.size(), half), b.end());
  //
  std::vector<int> z2 = karatsuba(a1, b1);
  std::vector<int> z0 = karatsuba(a0, a0);
  add_to(a0, a1, 0);
  add_to(b0, b1, 0);
  std::vector<int> z1 = karatsuba(a0, b0);
  sub_from(z1, z0);
  sub_from(z1, z2);
  std::vector<int> r;
  add_to(r, z0, 0);
  add_to(r, z1, half);
  add_to(r, z2, half + half);
  return r;
}

int solve(const std::string& M, const std::string& F) {
  int r = 0;
  int mn = M.size();
  int fn = F.size();
  std::vector<int> a(mn, 0);
  std::vector<int> b(fn, 0);
  for (int i = 0; i < mn; ++i)
    a[mn-i-1] = (M[i] == 'M');
  for (int i = 0; i < fn; ++i)
    b[i] = (F[i] == 'M');
  std::vector<int> c = karatsuba(a, b);
  for (int i = mn - 1; i < fn; ++i) {
    if (c[i] == 0)
      ++r;
  }

  return r;
}

int main() {

  // M = 1, F = 0
  //         m3 m2 m1 m0
  // *       n3 n2 n1 n0

  //                      n0m0 + n0m1 + n0m2 + n0m3
  //               n1m0 + n1m1 + n1m2 + n1m3
  //        n2m0 + n2m1 + n2m2 + n2m3
  // n3m0 + n3m1 + n3m2 + n3m3

  // C[i]
  int N;
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    int N;
    std::string M, F;
    std::cin >> M;
    std::cin >> F;
    printf("%d\n", solve(M, F));
  }

  return 0;
}
