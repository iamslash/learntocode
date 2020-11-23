/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <unordered_set>
#include <vector>

// 1 2
//
// 1 2
// 2 1

// // 760ms 1.60%
// // back tracking
// // O(N!) O(N)
// class Solution {
//  private:
//   int m_best;
//   int m_N;
//   std::unordered_set<int> m_ust;
//   void solve(int i, int n) {
//     // for (int k = 0; k < i; ++k)
//     //   printf("_");
//     // printf("i: %d, n: %d\n", i, n);
//     // base
//     if (i > 0 && i % n != 0 && n % i != 0)
//       return;
//     if (i >= m_N) {
//       m_best++;
//       // for (int k = 0; k < m_v.size(); ++k)
//       //   printf("%d ", m_v[k]);
//       // printf("\n");
//       return;
//     }

//     // recusrion
//     for (int nn = 1; nn <= m_N; ++nn) {
//       if (m_ust.count(nn) > 0)
//         continue;
//       m_ust.insert(nn);
//       solve(i+1, nn);
//       m_ust.erase(nn);
//     }
//   }
//  public:
//   int countArrangement(int N) {
//     m_best = 0;
//     m_N = N;
//     solve(0, 0);
//     return m_best;
//   }
// };

// 4ms 98.67%
// O(N!) O(N)
class Solution {
 private:
  int solve(int n, std::vector<int>& vs) {
    if (n <= 0)
      return 1;
    int r = 0;
    for (int i = 0; i < n; ++i) {
      if (vs[i] % n == 0 || n % vs[i] == 0) {
        std::swap(vs[i], vs[n-1]);
        r += solve(n-1, vs);
        std::swap(vs[i], vs[n-1]);
      }
    }
    return r;
  }
 public:
  int countArrangement(int N) {
    std::vector<int> vs;
    for (int i = 0; i < N; ++i)
      vs.push_back(i+1);
    return solve(N, vs);
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.countArrangement(4));
  
  return 0;
}
