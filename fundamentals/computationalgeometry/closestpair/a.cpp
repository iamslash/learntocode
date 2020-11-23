// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

class Point {
 public:
  Point() : x(0.0), y(0.0) {}
  Point(double _x, double _y) : x(_x), y(_y) {}
  double x, y;
  double dist(const Point& r) const {
    return hypot(r.x - this->x, r.y - this->y);
  }
};

double brute_force(const std::vector<Point>& v) {
  double r = std::numeric_limits<double>::max();
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      r = std::min(r, v[i].dist(v[j]));
      // printf("  %lf\n", r);
    }
  }
  return r;
}

double divide_and_conquer(const std::vector<Point>& xsorted,
                          const std::vector<Point>& ysorted) {
  int n = xsorted.size();

  // base condition
  if (n <= 3)
    return brute_force(xsorted);

  // recursion
  int mid =  (n-1) / 2;
  Point pmid = xsorted[mid];

  // make 2group ysorted
  std::vector<Point> pyl(mid+1);
  std::vector<Point> pyr(n-mid-1);
  int li = 0;
  int ri = 0;
  for (int i = 0; i < n; ++i) {
    if (ysorted[i].x <= pmid.x) {
      pyl[li++] = ysorted[i];
    } else {
      pyr[ri++] = ysorted[i];
    }
  }

  // 0, 1, 2, 3
  // get min dist from lgroup, rgroup
  std::vector<Point> pxl(xsorted.begin(), xsorted.begin() + mid + 1);
  std::vector<Point> pxr(xsorted.begin() + mid + 1, xsorted.end());
  double d = std::min(divide_and_conquer(pxl, pyl),
                     divide_and_conquer(pxr, pyr));

  // get min dist from cgroup
  std::vector<Point> pyc;
  for (int i = 0; i < n; ++i) {
    if (abs(ysorted[i].x - pmid.x) < d)
      pyc.push_back(ysorted[i]);
  }
  // this loop takes O(N) because inner loop takes 5 time at most
  for (int i = 0; i < pyc.size(); ++i) {
    for (int j = i+1; (j < pyc.size()) && pyc[j].y - pyc[i].y < d; ++j) {
      double d2 = pyc[i].dist(pyc[j]);
      d = std::min(d, d2);
    }
  }

  return d;
}

double solve(const std::vector<Point> v) {
  std::vector<Point> xsorted(v);
  std::vector<Point> ysorted(v);
  std::sort(xsorted.begin(), xsorted.end(),
            [](const Point& lhs, const Point& rhs) { return lhs.x < rhs.x; });
  std::sort(ysorted.begin(), ysorted.end(),
            [](const Point& lhs, const Point& rhs) { return lhs.y < rhs.y; });
  return divide_and_conquer(xsorted, ysorted);
}

int main() {
  std::vector<Point> v = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
  // std::vector<Point> v = {{2, 3}, {12, 30}, {40, 50}};
  printf("%lf\n", solve(v));
  return 0;
}
