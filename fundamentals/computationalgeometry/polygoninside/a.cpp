// Copyright (C) 2017 by iamslash

#include <cstdio>
#include <vector>

class Vector2 {
 public:
  int x;
  int y;
  Vector2(int a, int b) {
    x = a;
    y = b;
  }
};

bool solve(const std::vector<Vector2>& v, Vector2 p) {
  int cnt_cross = 0;
  for (int i = 0; i < v.size(); ++i) {
    int j = (i + 1) % v.size();
    if ((v[i].y > p.y) != (v[j].y > p.y)) {
      double at_x = (v[j].x - v[i].x) * (p.y - v[i].y) /
          (v[j].y - v[i].y) + v[i].x;
      if (p.x < at_x) {
        cnt_cross++;
      }
    }
  }
  // printf("%d\n", cnt_cross);
  return (cnt_cross & 1) > 0;
}

int main() {
  // {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  // {20, 20}
  std::vector<Vector2> v = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  Vector2 p = {20, 20};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {5, 5};
  printf("%s\n", solve(v, p) ? "true" : "false");

  v = {{0, 0}, {5, 5}, {5, 0}};
  p = {3, 3};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {5, 1};
  printf("%s\n", solve(v, p) ? "true" : "false");

  p = {8, 1};
  printf("%s\n", solve(v, p) ? "true" : "false");

  v = {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
  p = {-1, 10};
  printf("%s\n", solve(v, p) ? "true" : "false");

  return 0;
}
