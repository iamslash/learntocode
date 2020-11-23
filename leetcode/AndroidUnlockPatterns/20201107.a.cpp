/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 0 1 2
// 3 4 5
// 6 7 8

// 124ms 30.53% 8.2MB 69.23%
// bit sequence
// O(N!) O(N)
class Solution {
 private:
  std::vector<bool> m_seen = std::vector<bool>(9, false);
  // used: bit sequence of used cell
  bool isValid(int i, int last) {
    if (m_seen[i])
      return false;
    if (last == -1)
      return true;
    // knight moves or adjacent cells
    if ((i + last) % 2 == 1)
      return true;
    // (0,8), (8,0) with visited 4
    int mid = (i + last) / 2;
    if (mid == 4)
      return m_seen[mid];
    // moves not on same rows, columns
    if ((i % 3 != last % 3) && (i / 3 != last / 3))
      return true;
    // vertical, horizontal moves with visited waypoints
    return m_seen[mid];
  }
  int countOfPatterns(int last, int len) {
    if (len == 0)
      return 1;
    int cnt = 0;
    for (int i = 0; i < 9; ++i) {
      if (isValid(i, last)) {
        m_seen[i] = true;
        cnt += countOfPatterns(i, len - 1);
        m_seen[i] = false;
      }
    }
    return cnt;
  }
 public:
  int numberOfPatterns(int m, int n) {
    int rslt = 0;
    for (int len = m; len <= n; len++) {
      rslt += countOfPatterns(-1, len);
      for (int i = 0; i < 9; ++i)
        m_seen[i] = false;
    }
    return rslt;
  }
};

int main() {
  return 0;
}
