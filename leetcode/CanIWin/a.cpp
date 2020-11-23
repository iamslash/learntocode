/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 24ms 79.58%
class Solution {
 private:
  std::vector<int> m_C; // 0: false, 1: true
  int play(int M, int T, int U) {
    // base condition
    if (T <= 0)
      return 0;

    // memoization
    if (m_C[U] != -1)
      return m_C[U];

    // recursion
    for (int i = 0; i < M; ++i) {
      // used already
      if (U & (1 << i))
        continue;
      // to win the game next player should be fail
      if (play(M, T - (i+1), U | (1 << i)) == 0)
        return m_C[U] = 1;
    }
    
    return m_C[U] = 0;
  }
 public:
  bool canIWin(int M, int T) {
    int sum = M*(M+1)/2;
    if (sum < T)
      return false;
    if (T <= 1)
      return true;
    if (sum == T)
      return (M%2) == 1;
    m_C = std::vector<int>(1 << M, -1);
    return play(M, T, 0) == 1;
  }
};
 
void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Solution sln;  
  printb(sln.canIWin(2, 2));   // true
  return 0;
}
