// Copyright (C) 2016 by iamslash

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

struct Vector2
{
  double x, y;

  Vector2(double x = 0, double y = 0) : x(x), y(y) {}

  bool operator == (const Vector2& rhs) const 
  {
    return x == rhs.x && y == rhs.y;
  }

  bool operator < (const Vector2& rhs) const 
  {
    return x != rhs.x? x < rhs.x: y < rhs.y;
  }

  Vector2 operator + (const Vector2& rhs) const 
  {
    return Vector2(x + rhs.x, y + rhs.y);
  }

  Vector2 operator - (const Vector2& rhs) const 
  {
    return Vector2(x - rhs.x, y - rhs.y);
  }

  Vector2 operator * (double rhs) const 
  {
    return Vector2(x * rhs, y * rhs);
  }

  // 벡터의 길이
  double norm() const {return hypot(x, y);}

  Vector2 normalize() const
  {
    return Vector2(x / norm(), y / norm());
  }

  // x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
  double polar() const {return fmod(atan2(y, x) + 2 * PI, 2 * PI);}

  // 내적
  double dot(const Vector2& rhs) const
  {
    return x * rhs.x + y * rhs.y;
  }

  // 외적
  double cross(const Vector2& rhs) const
  {
    return x * rhs.y - y * rhs.x;
  }

  // rhs에 사영
  Vector2 project(const Vector2& rhs) const
  {
    Vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
};

typedef std::vector<Vector2> Polygon;

double ccw(Vector2 a, Vector2 b) {
  return a.cross(b);
}

double ccw(Vector2 p, Vector2 a, Vector2 b) {
  return ccw(p - a, p - b);
}

double solve(const Polygon& p) {
  int n = p.size();

  //
  int left = min_element(p.begin(), p.end()) - p.begin();
  int right = max_element(p.begin(), p.end()) - p.begin();

  //
  Vector2 calipers_l(0, 1);
  double r = (p[right] - p[left]).norm();

  // printf("(%lf, %lf) (%lf, %lf) %lf\n",
  //        p[left].x, p[left].y, p[right].x, p[right].y, r);

  //
  std::vector<Vector2> to_next(n);
  for (int i = 0; i < n; ++i) {
    to_next[i] = (p[(i+1) % n] - p[i]).normalize();
  }

  int a = left;
  int b = right;

  while (a != right || b != left) {
    double cos_l = calipers_l.dot(to_next[a]);
    double cos_r = -calipers_l.dot(to_next[b]);
    if (cos_l > cos_r) {
      calipers_l = to_next[a];
      a = (a + 1) % n;
    } else {
      calipers_l = to_next[b] * -1;
      b = (b + 1) % n;
    }
    r = std::max(r, (p[a] - p[b]).norm());
  }
  return r;
}

int N;

int main() {
  Polygon p = {{0, 0}, {3, 0}, {4, 2}, {3, 3},
               {0, 3}, {-1, 1}};
  printf("%lf", solve(p));

  return 0;
}
