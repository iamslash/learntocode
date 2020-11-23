/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_map>
#include <unordered_set>

// 48ms 28.38% 22.5MB 5.55%
class TicTacToe {
 private:
  std::unordered_map<int, std::unordered_set<int>> m_rows[2] = {};
  std::unordered_map<int, std::unordered_set<int>> m_cols[2] = {};
  std::unordered_map<int, int> m_ldia[2] = {};
  std::unordered_map<int, int> m_rdia[2] = {};
  int m_n;
 public:
  TicTacToe(int n) : m_n(n) {

  }
  int move(int y, int x, int p) {
    p--;
    // check diagonal lines
    if (y == x)
      m_ldia[p][y] = x;
    if (y == m_n - 1 - x)
      m_rdia[p][y] = x;
    // printf("(%d,%d) p:%d, size:%lu\n", y, x, p, m_rdia[p].size());
    if (m_ldia[p].size() == m_n ||
        m_rdia[p].size() == m_n)
      return p+1;
    // check cols, rows
    m_rows[p][y].insert(x);
    m_cols[p][x].insert(y);
    if (m_rows[p][y].size() == m_n ||
        m_cols[p][x].size() == m_n)
      return p+1;
    return 0;
  }
};


int main() {
  // TicTacToe ttt(3);
  // printf("%d\n", ttt.move(0, 0, 1));
  // printf("%d\n", ttt.move(0, 2, 2));
  // printf("%d\n", ttt.move(2, 2, 1));
  // printf("%d\n", ttt.move(1, 1, 2));
  // printf("%d\n", ttt.move(2, 0, 1));
  // printf("%d\n", ttt.move(1, 0, 2));
  // printf("%d\n", ttt.move(2, 1, 1));
  // TicTacToe ttt(2);
  // printf("%d\n", ttt.move(0, 1, 1));
  // printf("%d\n", ttt.move(1, 1, 2));
  // printf("%d\n", ttt.move(1, 0, 1));
  TicTacToe ttt(3);
  printf("%d\n", ttt.move(1, 1, 2));
  printf("%d\n", ttt.move(0, 2, 2));
  printf("%d\n", ttt.move(2, 0, 2));
  
  return 0;
}

// . . 2
// . 2 .
// 2 . .
