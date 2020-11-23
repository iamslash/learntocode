// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

// int modinv(int a, int M) {
//   int r = 1;
//   int n = M - 2;
//   for (int i = 0; i < n; ++i)
//     r *= a % M;
//   r %= M;
//   printf("%d %d : %d\n", a, M, r);
//   return r;
// }

int xgcd(int a, int b, int& x, int &y) {
    // baseb condition
    if (b == 0) {
        x = 1;
        y = 0;
        // printf("%d = %d * %d + %d * %d\n", a, a, x, b, y); 
        return a;
    }

    // recursion
    int x1, y1;
    int gcd = xgcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - a/b * y1;
    // printf("%d = %d * %d + %d * %d\n", gcd, a, x, b, y);
    return gcd;
}

int modinv(int a, int M) {
  int x, y;
  int gcd = xgcd(a, M, x, y);
  return x >= 0 ? x : x + M;
}

int solve(const std::vector<int>& num, const std::vector<int>& rem) {
  int n = num.size();
  int prd = 1;
  int r = 0; // result

  for (int i = 0; i < n; ++i)
    prd *= num[i];
  for (int i = 0; i < n; ++i) {
    int pbi = prd / num[i];
    r += rem[i] * modinv(pbi, num[i]) * pbi;
  }

  return r % prd;
}

int main() {
  std::vector<int>num = {3, 4, 5};
  std::vector<int>rem = {2, 3, 1};
  printf("%d\n", solve(num, rem));
  // printf("%d\n", modinv(15, 4));
  return 0;
}
