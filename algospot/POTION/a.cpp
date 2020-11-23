// Copyright (C) 2017 by iamslash
// https://algospot.com/judge/problem/read/POTION

#include <vector>
#include <cmath>

int N;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

std::vector<int> solve(const std::vector<int>& R,
                       const std::vector<int>& P) {
  std::vector<int> r(N);

  // get X
  double X = 0.0;
  for (int i = 0; i < N; ++i) {
    X = fmax(X, static_cast<double>(P[i]) / R[i]);
  }

  // get b
  int b = R[0];
  for (int i = 1; i < N; ++i) {
    b = gcd(b, R[i]);
  }

  // get a
  // Y is 1 at least
  int a = ceil(X * b);

  for (int i = 0; i < N; ++i) {
    r[i] = R[i] * a / b - P[i];
  }

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    std::vector<int> R(N);
    std::vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &R[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &P[i]);
    }
    std::vector<int> A = solve(R, P);
    for (int a : A) {
      printf("%d ", a);
    }
    printf("\n");
  }
  return 0;
}

// int main() {
//   double d = 2 / (double)3;
//   printf("%lf", d);
//   return 0;
// }
