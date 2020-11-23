// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int _x, int _y) {
    x = _x;
    y = _y;
  }
  bool operator == (const Vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
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
  double norm() const { return hypot(x, y); }
};

// positive number for ccw b from a
// negative number for cw b from a
double ccw(Vector2 a, Vector2 b) {
  return a.cross(b);
}

double ccw(Vector2 p, Vector2 a, Vector2 b) {
  return ccw(a-p, b-p);
}

typedef std::vector<Vector2> Polygon;

bool mycomp(Vector2 l, Vector2 r) {
  if (l.x < r.x) {
    return true;
  } else if (l.x == r.x) {
    return l.y < r.y;
  }
  return false;
}

Polygon solve(const Polygon& p) {
  int n = p.size();
  Polygon hull;

  Vector2 pivot = *std::min_element(p.begin(), p.end(), mycomp);
  hull.push_back(pivot);

  while (true) {
    Vector2 ph = hull.back();
    Vector2 next = p[0];
    for (int i = 1; i < n; ++i) {
      double cross = ccw(ph, next, p[i]);
      double dist = (next - ph).norm() - (p[i] - ph).norm();
      if (cross > 0 || (cross == 0 && dist < 0))
        next = p[i];
    }
    if (next == pivot)
      break;
    hull.push_back(next);
  }
  
  return hull;
}

int main() {
  Polygon p = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
               {3, 0}, {0, 0}, {3, 3}};
  
  Polygon r = solve(p);

  for (Vector2 v : r) {
    printf("(%d, %d) ", v.x, v.y);
  }
  printf("\n");
  
  return 0;
}

