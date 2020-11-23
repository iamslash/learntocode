/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <random>
#include <iostream>

// circle equation
// x^2 + y^2 <= r^2

// rejection sampling
// 132ms 98.35% 27.6MB 58.96%
// O(1) O(1)
class Solution {
 private:
  double m_r;
  double m_cx;
  double m_cy;
 public:
  Solution(double r, double cx, double cy) {
    m_r = r;
    m_cx = cx;
    m_cy = cy;
  }
    
  std::vector<double> randPoint() {
    double dx;
    double dy;
    do {
      dx = (2 * ((double)std::rand() / RAND_MAX) - 1.0) * m_r;
      dy = (2 * ((double)std::rand() / RAND_MAX) - 1.0) * m_r;
    } while (dx*dx + dy*dy > m_r*m_r);

    return {m_cx+dx, m_cy+dy};
  }
};

int main() {
  // Solution sln(1, 0, 0);
  // for (int i = 0; i < 10; ++i) {
  //   auto a = sln.randPoint();
  //   printf("%lf, %lf\n", a[0], a[1]);
  // }

  printf("%d %d\n", std::rand(), RAND_MAX);
  
  return 0;
}


// int main()
// {
//   std::default_random_engine g;
//   std::uniform_real_distribution<double> d (0.0, 100.0);

//   for (int i=0; i<10; ++i)
//     printf("%lf\n", d(g));

//   return 0;
// }
