// Copyright (C) 2017 by iamslash

// https://leetcode.com/problems/n-queens-ii/description/
// https://www.hackerrank.com/challenges/queens-on-board/problem

#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

// class Solution {
//  public:
//   int m_cnt;
//   vector<int> m_rows;

//   int valid(int row) {
//     if (row == 0)
//       return true;
//     for (int i = 0; i < row; ++i) {
//       if (m_rows[i] == m_rows[row])
//         return false;
//       if (abs(i - row) == abs(m_rows[i] - m_rows[row]))
//         return false;
//     }
//     return true;
//   }
//   void solve(int row) {
//     // base condition
//     if (row == m_rows.size()) {
//       ++m_cnt;
//       return;
//     }
//     // recursion
//     for (int col = 0; col < m_rows.size(); ++col) {
//       m_rows[row] = col;
//       if (valid(row))
//         solve(row+1);
//     }
//   }
//   int totalNQueens(int n) {
//     m_cnt = 0;
//     m_rows = vector<int>(n, -1);
//     solve(0);
//     return m_cnt;
//   }
// };

class Solution {
 public:
  int m_cnt;
  int m_end;
  void solve(int row, int ld, int rd) {
    if (row == m_end) {
      m_cnt++;
      return;
    }
    int pos = m_end & (~(row | ld | rd));
    while (pos != 0) {
      int p = pos & (-pos); // pickup rightmost one
      pos -= p;
      solve(row + p, (ld + p) << 1, (rd + p) >> 1);
    }
  }
  int totalNQueens(int n) {
    m_cnt = 0;
    m_end = (1 << n) - 1;
    solve(0, 0, 0);
    return m_cnt;
  }
};

int main() {
  Solution s;
  printf("%d\n", s.totalNQueens(10));
  return 0;
}
