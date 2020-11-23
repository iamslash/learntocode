/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 20ms 92.99% 14.6MB 21.31%
// sumRegion: O(W) O(HW)
//    update: O(W) O(HW)
class NumMatrix {
 private:
  std::vector<std::vector<int>> m_rowsums;
 public:
  NumMatrix(std::vector<std::vector<int>>& M) {
    if (M.empty() || M[0].empty())
      return;
    int h = M.size();
    int w = M[0].size();
    for (int y = 0; y < h; ++y) {
      std::vector<int> rowsum;
      int sum = 0;
      for (int x = 0; x < w; ++x) {
        sum += M[y][x];
        rowsum.push_back(sum);
      }
      m_rowsums.push_back(rowsum);
    }
  }
    
  void update(int r, int c, int val) {
    int leftsum = c > 0 ? m_rowsums[r][c-1] : 0;
    int delta = val - (m_rowsums[r][c] - leftsum);
    for (int x = c; x < m_rowsums[r].size(); ++x)
      m_rowsums[r][x] += delta;
  }
    
  int sumRegion(int lty, int ltx, int rby, int rbx) {
    int sum = 0;
    for (int y = lty; y <= rby; ++y) {
      int leftsum = ltx > 0 ? m_rowsums[y][ltx-1] : 0;
      sum += m_rowsums[y][rbx] - leftsum;
    }
    return sum;      
  }
};

int main() {
  
  // std::vector<std::vector<int>> M = {
  //   {3, 0, 1, 4, 2},
  //   {5, 6, 3, 2, 1},
  //   {1, 2, 0, 1, 5},
  //   {4, 1, 0, 1, 7},
  //   {1, 0, 3, 0, 5}
  // };

  std::vector<std::vector<int>> M = {
    {1},
    {2}
  };

  NumMatrix nm(M);
  printf("%d\n", nm.sumRegion(0, 0, 0, 0));
  printf("%d\n", nm.sumRegion(1, 0, 1, 0));
  printf("%d\n", nm.sumRegion(0, 0, 1, 0));
  nm.update(0, 0, 3);
  nm.update(1, 0, 5);
  printf("%d\n", nm.sumRegion(0, 0, 1, 0));

  return 0;
}
