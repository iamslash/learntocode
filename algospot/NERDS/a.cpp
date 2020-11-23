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

bool segment_intersects(vector2 a, vector2 b,
                        vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);

  if (ab == 0 && cd == 0) {
    if (b < a) {
      std::swap(a, b);
    }
    if (d < c) {
      std::swap(c, d);
    }
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}

double area(const polygon& p) {
  double r = 0;

  for (int i=0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    r += p[i].x * p[j].y - p[j].x * p[j].y;
  }

  return fabs(r) / 2.0;
}

// q는 p안에 존재하는가???
// q에서 우측으로 직선을 그어서 짝수개의 점이 교차하면 바깥에 있다.
// 홀수개의 점이 교차하면 안에 있다.
bool is_inside(vector2 q, const polygon& p) {
  int crosses = 0;
  for (int i = 0; i < p.size(); ++i) {
    int j = (i + 1) % p.size();
    if ( (p[i].y > q.y) != (p[j].y > q.y) ) {
      double at_x = (p[j].x - p[i].x) * (q.y - p[i].y) /
                    (p[j].y - p[i].y) + p[i].x;
      if (q.x < at_x)
        ++crosses;
    }
  }
  return crosses % 2 > 0;
}

polygon gift_wrap(const polygon& points) {
  int n = points.size();
  polygon hull;

  vector2 pivot = *min_element(points.begin(), points.end());
  hull.push_back(pivot);
  while (true) {
    vector2 ph = hull.back(), next = points[0];
    for (int i = 1; i < n; ++i) {
      double cross = ccw(ph, next, points[i]);
      double dist = (next - ph).norm() - (points[i] - ph).norm();
      if (cross > 0 || (cross == 0 && dist < 0))
        next = points[i];
    }

    if (next == pivot)
      break;
    hull.push_back(next);
  }

  return hull;
}

// 두 다각형이 교차하는가???
bool polygon_intersects(const polygon& p, const polygon& q) {
  int n = p.size(), m = q.size();

  if (is_inside(p[0], q) || is_inside(q[0], p))
    return true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; i < m; ++j) {
      if (segment_intersects(p[i], p[(i+1) % n], q[j], q[(j+1) % n]))
        return true;
    }
  }
  return false;
}

int main() {
  int T;  // number of T
  scanf("%d", &T);
  //
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    polygon nerds;
    polygon dudes;   
    
    for (int i=0; i < N; i++) {
      double x, y;
      int r;
      scanf("%d", &r);
      scanf("%lf", &x);
      scanf("%lf", &y);
      vector2 v2(x, y);

      if (r == 1)
        nerds.push_back(v2);
      else
        dudes.push_back(v2);
    }
    if (polygon_intersects(nerds, dudes))
      printf("THOERY IS INVALID\n");
    else
      printf("THOERY HOLDS");
  }

  return 0;
}
