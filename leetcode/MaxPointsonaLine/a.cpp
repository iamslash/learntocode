/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_map>
#include <limits>
#include <string>

struct Point {
  int x;
  int y;
  // Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

// [1,1] [3,2] [5,3] [4,1] [2,3] [1,4]
// Time : O(N^2), Space: O(N)
// 20ms ????
class Solution {
 private:
  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
  }
 public:
  int maxPoints(std::vector<Point>& P) {
    if (P.size() < 2)
      return P.size();
    int rslt = 0;
    for (int i = 0; i < P.size(); ++i) {
      int same_pt = 0;
      int inf_slope = 0;
      int local_max = 0;
      std::unordered_map<std::string, int> ump;
      for (int j = i + 1; j < P.size(); ++j) {
        if (P[i].x == P[j].x && P[i].y == P[j].y) {
          same_pt++;
        } else if (P[i].x == P[j].x) {
          inf_slope++;
        } else {
          int dy = P[i].y - P[j].y;
          int dx = P[i].x - P[j].x;
          int g  = gcd(dy, dx);
          dy /= g;
          dx /= g;
          if (dy < 0) {
            dy = -dy;
            dx = -dx;
          }
          std::string s = std::to_string(dy)+","+std::to_string(dx);
          // printf("i:%d j:%d dy:%d dx:%d g:%d s:%s\n", i, j, dy, dx, g, s.c_str());
          ump[s]++;
          local_max = std::max(local_max, ump[s]);
          // printf("i:%d j:%d s:%s\n", i, j, s.c_str());
        }
        local_max = std::max(local_max, inf_slope);
      }
      rslt = std::max(rslt, local_max + same_pt);
    }
    return rslt+1; 
  }
};

int main() {
  // std::vector<Point> V = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
  // std::vector<Point> V = {{1,1},{2,2},{3,3}}; // 2
  // std::vector<Point> V = {{2,3},{3,3},{-5,3}};  // 3
  // std::vector<Point> V = {{0,0},{1,1},{1,-1}};
  // std::vector<Point> V = {{0,0},{1,0},{2,1}}; // 2
  std::vector<Point> V = {{0,0},{94911151,94911150},{94911152,94911151}}; // 2
  Solution sln;
  printf("%d\n", sln.maxPoints(V));
  
  return 0;
}
