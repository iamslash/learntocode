// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/ROOTS

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

const double L = 25;

int N;

vector<double> differentiate(const vector<double>& poly) {
    vector<double> r;
    for (int i = 0; i < poly.size() - 1; i++)
      r.push_back((poly.size() - 1 - i) * poly[i]);
    return r;
}

vector<double> solve_naive(const vector<double>& poly) {
    vector<double> r;

    if (poly.size() == 2) {  // 1차 방정식
        r.push_back(-poly[1] / poly[0]);
    } else if (poly.size() == 3) {  // 2차 방정식
        double a = poly[0], b = poly[1], c = poly[2];
        r.push_back((-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) );
        r.push_back((-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a) );
    }
    sort(r.begin(), r.end());
    return r;
}

// return f(x0)
double evaluate(const vector<double>& poly, double x0) {
    double r = 0;
    for (int i = 0; i <= poly.size() - 1 ; i++)
        r += pow(x0, poly.size() - 1 - i) * poly[i];
    return r;
}

vector<double> solve(const vector<double>& poly) {
  int n = poly.size() - 1;

  // base condition
  if (n <= 2) return solve_naive(poly);

  vector<double> derivative = differentiate(poly);
  vector<double> sols = solve(derivative);

  sols.insert(sols.begin(), -L-1);
  sols.insert(sols.end(), L+1);

  vector<double> r;

  for (int i=0; i+1 < sols.size(); ++i) {
    double x1 = sols[i];
    double x2 = sols[i+1];
    double y1 = evaluate(poly, x1);
    double y2 = evaluate(poly, x2);

    if (y1 * y2 > 0)
      continue;

    if (y1 > y2) {
      swap(y1, y2);
      swap(x1, x2);
    }

    // 이분법
    for (int i=0; i < 100; ++i) {
      double mx = (x1 + x2) / 2;
      double my = evaluate(poly, mx);
      if (y1*my > 0) {
        y1 = my;
        x1 = mx;
      } else {
        y2 = my;
        x2 = mx;
      }
    }

    r.push_back((x1 + x2) / 2);
  }
  sort(r.begin(), r.end());
  return r;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  for (int t=0; t < T; ++t) {
    scanf("%d", &N);
    vector<double> poly;
    vector<double> sols;

    for (int i = 0; i < N; i++) {
      double d;
      scanf("%lf", &d);
      poly.push_back(d);
    }
    sols = solve(poly);
    // 해답출력
    for (int i = 0; i < sols.size(); i++) {
      printf("%0.12lf ", sols[i]);
    }
    printf("\n");
  }

  return 0;
}
