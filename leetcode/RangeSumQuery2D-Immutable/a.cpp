/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>


// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
//
// 1 2  3  4
// 2 4  6  8
// 3 6  9 12
// 4 8 12 16

// 16ms 81.90%
class NumMatrix {
 private:
  std::vector<std::vector<int>> m_PS;
 public:
  NumMatrix(std::vector<std::vector<int>> M) {
    m_PS = M;
    for (int y = 0; y < M.size(); ++y) {
      for (int x = 0; x < M[0].size(); ++x) {
        if (y > 0)
          m_PS[y][x] += m_PS[y-1][x];
        if (x > 0)
          m_PS[y][x] += m_PS[y][x-1];
        if (x > 0 && y > 0)
          m_PS[y][x] -= m_PS[y-1][x-1];
        // printf("%2d ", m_PS[y][x]);        
      }
      // printf("\n");
    }
  }
    
  int sumRegion(int y1, int x1, int y2, int x2) {
    int rslt = m_PS[y2][x2];
    if (y1 > 0)
      rslt -= m_PS[y1-1][x2];
    if (x1 > 0)
      rslt -= m_PS[y2][x1-1];
    if (y1 > 0 && x1 > 0)
      rslt += m_PS[y1-1][x1-1];
    return rslt;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */

int main() {
  
  std::vector<std::vector<int>> M = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  };
  NumMatrix nm(M);
  printf("%d\n", nm.sumRegion(2, 1, 4, 3));
  printf("%d\n", nm.sumRegion(1, 1, 2, 2));
  printf("%d\n", nm.sumRegion(1, 2, 2, 4));
  
  return 0;
}
