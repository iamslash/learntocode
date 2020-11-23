// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <string>

// 1
// 10
// 100
// 101
// 11
// 12
// 13
// 2
// 3

// // recursive way dfs
// // 184ms 45.50%
// class Solution {
//  private:
//   std::vector<int> m_rslt;
//   int m_n;
//   void dfs(int step) {
//     int last = m_rslt.back();
//     last *= 10;
//     // base
//     if (last > m_n)
//       return;

//     // recursion
//     for (int i = last; i <= last+9; ++i) {
//       m_rslt.push_back(i);
//       if (i >= m_n)
//         break;
//       dfs(step+1);
//     }
//   }
//  public:
//   std::vector<int> lexicalOrder(int n) {
//     m_n = n;
//     for (int i = 1; i <= 9; ++i) {
//       m_rslt.push_back(i);
//       if (i >= n)
//         break;
//       dfs(0);
//     }
//     return m_rslt;         
//   }
// };

//
// r: 1 10 11 12 13 2 ... 9
// a: 
// iterative way
// 84ms 99.73%
class Solution {
 public:
  std::vector<int> lexicalOrder(int n) {
    std::vector<int> rslt(n, 0);
    int a = 1;
    for (int i = 0; i < n; ++i) {
      rslt[i] = a;
      if (a * 10 <= n) {
        a *= 10;
      } else {
        if (a >= n)
          a /= 10;
        a++;
        while(a % 10 == 0)
          a /= 10;        
      }
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  auto rslt = sln.lexicalOrder(13);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
}
