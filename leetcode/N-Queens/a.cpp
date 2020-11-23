/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// // 4ms 75.68%
// // O(N^3) O(N)
// class Solution {
//  private:
//   std::vector<int> m_Q;
//   std::vector<std::vector<std::string>> m_rslt;
//   int m_n;
//   bool isValidPos(int y, int x) {
//     int i, j;
//     // upper column
//     for (i = 0; i < y; ++i)
//       if (m_Q[i] == x)
//         return false;

//     // left upper diagonal
//     for (i = y, j = x; i >= 0 && y >= 0; --i, --j)
//       if (m_Q[i] == j)
//         return false;

//     // right upper diagonal
//     for (i = y, j = x; i >= 0 && j < m_n; --i, ++j)
//       if (m_Q[i] == j)
//         return false;

//     return true;
//   }
//   void solve(int y) {
//     // printf("%d\n", y);
//     // base
//     if (y >= m_n) {
//       std::vector<std::string> block(
//           m_n, std::string(m_n, '.'));
//       m_rslt.push_back(block);
//       for (int i = 0; i < m_n; ++i) {
//         m_rslt.back()[i][m_Q[i]] = 'Q';
//       }
//       return;
//     }
    
//     // recursion
//     for (int x = 0; x < m_n; ++x) {
//       if (isValidPos(y, x)) {
//         m_Q[y] = x;
//         solve(y+1);
//         m_Q[y] = -1;
//       }
//     }
//   }
//  public:
//   std::vector<std::vector<std::string>> solveNQueens(int n) {
//     m_Q = std::vector<int>(n, -1);
//     m_n = n;
//     solve(0);
//     return m_rslt;
//   }
// };

// 0ms 100.00%
// O(N^2) O(N)
class Solution {
 private:
  std::vector<int> m_Q;
  std::vector<std::vector<std::string>> m_rslt;
  int m_END;  // bit sequences of end condition (ex. 11111)
  int m_n;
  void solve(int y, int vr, int ld, int rd) {
    // base
    if (vr == m_END) {
      std::vector<std::string> block(m_n, std::string(m_n, '.'));
      for (int i = 0; i < m_n; ++i)
        block[i][m_Q[i]] = 'Q';
      m_rslt.push_back(block);
      return;
    }

    // recursion
    int last = m_END & (~(vr | ld | rd));
    while (last != 0) {
      int pos = last & (-last);
      last -= pos;
      int x = __builtin_ctz(pos);
      
      m_Q[y] = x;
      solve(y+1, vr + pos, (ld + pos) << 1, (rd + pos) >> 1);
      m_Q[y] = -1;
    }
  }  
 public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    m_n = n;
    m_Q = std::vector<int>(n, -1);
    m_END = (1 << n) - 1;
    solve(0, 0, 0, 0);
    return m_rslt;
  }
};

int main() {
  Solution sln;
  auto rslt = sln.solveNQueens(4);
  for (const auto& block : rslt) {
    printf("=====\n");
    for (const auto& line : block) {
      printf("%s\n", line.c_str());
    }
    printf("\n");
  }
  return 0;
}
