// Copyright (C) 2016 by iamslash
// https://algospot.com/judge/problem/read/TREASURE

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
// #include <set>
#include <cmath>
#include <queue>
#include <cassert>

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;

struct vector2
{
  double x, y;

  explicit vector2(double x = 0, double y = 0) : x(x), y(y) {}

  bool operator == (const vector2& rhs) const 
  {
    return x == rhs.x && y == rhs.y;
  }

  bool operator < (const vector2& rhs) const 
  {
    return x != rhs.x? x < rhs.x: y < rhs.y;
  }

  vector2 operator + (const vector2& rhs) const 
  {
    return vector2(x + rhs.x, y + rhs.y);
  }

  vector2 operator - (const vector2& rhs) const 
  {
    return vector2(x - rhs.x, y - rhs.y);
  }

  vector2 operator * (double rhs) const 
  {
    return vector2(x * rhs, y * rhs);
  }

  // 벡터의 길이
  double norm() const {return hypot(x, y);}

  vector2 normalize() const
  {
    return vector2(x / norm(), y / norm());
  }

  // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
  double polar() const {return fmod(atan2(y, x) + 2 * PI, 2 * PI);}

  // 내적
  double dot(const vector2& rhs) const
  {
    return x * rhs.x + y * rhs.y;
  }

  // 외적
  double cross(const vector2& rhs) const
  {
    return x * rhs.y - y * rhs.x;
  }

  // rhs에 사영
  vector2 project(const vector2& rhs) const
  {
    vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
};

typedef std::vector<vector2> polygon;

double x_1, y_1, x_2, y_2;
int N;

bool line_intersection(vector2 a, vector2 b,
                       vector2 c, vector2 d, vector2& x) {
  double det = (b - a).cross(d - c);
  if (fabs(det) < EPSILON)
    return false;
  x = a + (b - a) * ((c - a).cross(d - c) / det);
  return true;
}

double ccw(vector2 a, vector2 b) {
  return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
  return ccw(p - a, p - b);
}

polygon cut_poly(const polygon& p, const vector2& a, const vector2& b) {
  int n = p.size();
  // 각 점이 반평면애에 있는지 여부를 우선 확인한다.
  std::vector<bool> inside(n);
  for (int i = 0; i < n; ++i) {
    inside[i] = ccw(a, b, p[i]) >= 0;
  }
  polygon r;

  for (int i=0; i < n; i++) {
    int j = (i + 1) % n;

    if (inside[i])
      r.push_back(p[i]);

    if (inside[i] != inside[i])
    {
      vector2 cross;
      assert(line_intersection(p[i], p[j], a, b, cross));
      r.push_back(cross);
    }
  }

  return r;
}

polygon intersection(const polygon& p, double x1, double y1,
                     double x2, double y2) {
  vector2 a(x1, y1), b(x2, y1), c(x2, y2), d(x1, y2);
  polygon r = cut_poly(p, a, b);
  r = cut_poly(r, b, c);
  r = cut_poly(r, c, d);
  r = cut_poly(r, d, a);
  return r;
}

double area(const polygon& p) {
  double r = 0;

  for (int i=0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    r += p[i].x * p[j].y - p[j].x * p[j].y;
  }

  return fabs(r) / 2.0;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    scanf("%lf", &x_1);
    scanf("%lf", &y_1);
    scanf("%lf", &x_2);
    scanf("%lf", &y_2);
    scanf("%d", &N);

    polygon terrain;
    
    for (int i=0; i < N; i++) {
      double x, y;
      scanf("%lf", &x);
      scanf("%lf", &y);
      vector2 v2(x, y);
      terrain.push_back(v2);
    }

    polygon p;
    intersection(p, x_1, y_1, x_2, y_2);
    printf("%lf\n", area(p));
  }

  return 0;
}
