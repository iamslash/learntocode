// Copyright (C) 2017 by iamslash

// cos(x)    = y
// acos(y)   = (x)
// cos(π/2) = 0
// acos(0)   = π/2

#include <cstdio>
#include <limits>
#include <cmath>
#include <string>

const double PI = 2.0 * acos(0.0);

struct vector2 {
  double   x, y;
  explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
  bool operator == (const vector2& rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  // ???
  bool operator < (const vector2& rhs) const {
    return x != rhs.x ? x < rhs.x : y < rhs.y;
  }
  vector2 operator + (const vector2& rhs) const {
    return vector2(x + rhs.x, y + rhs.y);
  }
  vector2 operator - (const vector2& rhs) const {
    return vector2(x - rhs.x, y - rhs.y);
  }
  vector2 operator * (double rhs) const {
    return vector2(x * rhs, y * rhs);
  }
  double norm() const { return hypot(x, y); }
  vector2 normalize() const {
    return vector2(x / norm(), y / norm());
  }
  // angle from x-axis ccw (count clock wise)
  double polar() const {
    return fmod(atan2(y, x) + 2 * PI, 2 * PI);
  }
  double dot(const vector2& rhs) const {
    return x * rhs.x + y * rhs.y;
  }
  double cross(const vector2& rhs) const {
    return x * rhs.y - rhs.x * y;
  }
  // a vector projected to this vector
  vector2 project(const vector2& rhs) const {
    vector2 r = rhs.normalize();
    return r * r.dot(*this);
  }
  double howmuchcloser(vector2 p, vector2 a, vector2 b) {
    return (b - p).norm() - (a - p).norm();
  }
  // positive number for ccw b from a
  // negative number for cw b from a
  double ccw(vector2 a, vector2 b) {
    return a.cross(b);
  }
  double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
  }
    
  std::string tostring() const {
    char buf[32] = {0, };
    snprintf(buf, sizeof(buf), "(%0.2lf, %0.2lf)", x, y);
    return buf;
  }
};

double ccw(vector2 a, vector2 b) {
  return a.cross(b);
}

double ccw(vector2 p, vector2 a, vector2 b) {
  return ccw(a-p, b-p);
}

bool line_intersection(vector2 a, vector2 b,
                       vector2 c, vector2 d,
                       vector2& x) {
  double det = (b - a).cross(d - c);
  if (fabs(det) < std::numeric_limits<double>::epsilon())
    return false;
  x = a + (b - a) * ((c - a).cross(d - c) / det);
  return true;
}

bool pararrel_segments(vector2 a, vector2 b,
                         vector2 c, vector2 d,
                         vector2& p) {
  if (b < a)
    std::swap(a, b);
  if (d < c)
    std::swap(c, d);
  // not on the same line, not overlapping case
  if (ccw(a, b, c) != 0 || b < c || d < a)
    return false;
  // two segments overlap
  if (a < c)
    p = c;
  else
    p = a;
  return true;
}

bool in_bounding_rectangle(vector2 p, vector2 a, vector2 b) {
  if (b < a)
    std::swap(a, b);
  return p == a || p == b || (a < p && p < b);
}

bool segment_intersection(vector2 a, vector2 b,
                         vector2 c, vector2 d,
                         vector2& p) {
  if (!line_intersection(a, b, c, d, p))
    return pararrel_segments(a, b, c, d, p);
  return in_bounding_rectangle(p, a, b) &&
      in_bounding_rectangle(p, c, d);
}

bool segment_intersect(vector2 a, vector2 b,
                       vector2 c, vector2 d) {
  double ab = ccw(a, b, c) * ccw(a, b, d);
  double cd = ccw(c, d, a) * ccw(c, d, b);
  // two segments on the same line
  // end point overlap
  if (ab == 0 && cd == 0) {
    if (b < a)
      std::swap(a, b);
    if (d < c)
      std::swap(c, d);
    return !(b < c || d < a);
  }
  return ab <= 0 && cd <= 0;
}

int main() {
  vector2 v(2.0, 3.0);
  printf("%s\n", v.tostring().c_str());
  return 0;
}

