// Copyright (C) 2017 by iamslash

#include <cmath>
#include <cstdio>
#include <vector>

const double PI = 2.0 * acos(0.0);
const double EPSILON = 1e-9;

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int _x, int _y) {
    x = _x;
    y = _y;
  }

  Vector2 operator + (const Vector2& rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
  }
  Vector2 operator * (double rhs) const {
    return Vector2(x * rhs, y * rhs);
  }
  Vector2 operator - (const Vector2& rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
  }
  double cross(const Vector2& rhs) const {
    return x * rhs.y - rhs.x * y;
  }
};

// positive number for ccw b from a
// negative number for cw b from a
double ccw(Vector2 a, Vector2 b) {
  return a.cross(b);
}

double ccw(Vector2 p, Vector2 a, Vector2 b) {
  return ccw(a-p, b-p);
}

bool line_intersection(Vector2 a, Vector2 b,
                       Vector2 c, Vector2 d,
                       Vector2& x) {
  double det = (b - a).cross(d - c);
  // in case of pararrel
  if (fabs(det) < EPSILON)
    return false;
  x = a + (b - a) * ((c - a).cross(d - c) / det);
  return true;
}

typedef std::vector<Vector2> Polygon;


Polygon cut(const Polygon& p, const Vector2& a, const Vector2& b) {
  Polygon r;
  int n = p.size();
  std::vector<bool> inside(n);
  // check p[i] is inside clipper
  for (int i = 0; i < n; ++i)
    inside[i] = ccw(a, b, p[i]) >= 0;
  // save points which is inside in clipper or intersect with cliper
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    if (inside[i])
      r.push_back(p[i]);
    if (inside[i] != inside[j]) {
      Vector2 cross(0, 0);
      line_intersection(p[i], p[j], a, b, cross);
      r.push_back(cross);
    }
  }
  return r;
}

Polygon solve(const Polygon& C, const Polygon& P) {
  Vector2 a = C[0];
  Vector2 b = C[3];
  Vector2 c = C[2];
  Vector2 d = C[1];
  Polygon r;
  r = cut(P, a, b);
  r = cut(r, b, c);
  r = cut(P, c, d);
  r = cut(P, d, a);
  return r;
}

int main() {
  Polygon clipper = {{150, 150}, {150, 200},
                     {200, 200}, {200, 150}};
  Polygon clippee = {{100, 150}, {200, 250}, {300, 200}};
  Polygon p = solve(clipper, clippee);
  // (150, 162) (150, 200) (200, 200) (200, 174)
  for (int i = 0; i < p.size(); ++i) {
    printf("(%d, %d) ", p[i].x, p[i].y);
  }
  printf("\n");
  return 0;
}
