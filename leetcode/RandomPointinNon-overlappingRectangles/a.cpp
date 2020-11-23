/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <random>
#include <map>

// // 148ms 15.12% 38.6MB 5.15%
// // reservoir sampling
// class Solution {
//  private:
//   std::vector<std::vector<int>> m_R;
//  public:
//   Solution(std::vector<std::vector<int>> R) : m_R(R) {        
//   }
    
//   std::vector<int> pick() {
//     int sum = 0;
//     std::vector<int> rect;
//     for (auto r : m_R) {
//       int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
//       sum += area;
//       if (std::rand() % sum < area)
//         rect = r;
//     }
//     int x = rect[0] + std::rand() % (rect[2] - rect[0] + 1);
//     int y = rect[1] + std::rand() % (rect[3] - rect[1] + 1);    
//     return {x, y};
//   }
// };

// 92ms 96.36% 27.2MB 44.97%
class Solution {
 private:
  std::vector<std::vector<int>> m_R;
  int m_sum;
  std::map<int, int> m_area2idx;
 public:
  Solution(std::vector<std::vector<int>> R) {
    m_R = R;
    m_sum = 0;
    for (auto r : R) {
      m_sum += (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
      m_area2idx[m_sum] = m_area2idx.size();
    }
  }
  std::vector<int> pick() {
    int val = std::rand() % m_sum;
    int i   = m_area2idx.upper_bound(val)->second;
    int w   = m_R[i][2] - m_R[i][0] + 1;
    int h   = m_R[i][3] - m_R[i][1] + 1;
    int x   = std::rand() % w + m_R[i][0];
    int y   = std::rand() % h + m_R[i][1];
    return {x, y};
  }
};

int main() {
  // std::vector<std::vector<int>> R = {
  //   {1, 1, 5, 5}};
  // // std::vector<std::vector<int>> R = {
  // //   {-2, -2, -1, -1},
  // //   {1, 0, 3, 0}
  // // };
  // Solution sln(R);
  // for (int i = 0; i < 5; ++i) {
  //   auto rslt = sln.pick();
  //   printf("[%d, %d]\n", rslt[0], rslt[1]);
  // } 
  
  return 0;
}
