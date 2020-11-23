/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>
#include <functional>

// // recursive way
// // 848ms 6.87%
// class Solution {
//  private:
//   int m_rslt;
//   std::vector<int> m_V;
//   void solve(int pos, int tgt) {
//     // base
//     if (pos >= m_V.size()) {
//       if (tgt == 0)
//         m_rslt++;
//       return;
//     }

//     // recursion
//     int num = m_V[pos];
//     solve(pos+1, tgt-num);
//     solve(pos+1, tgt+num);
//   }
//  public:
//   int findTargetSumWays(std::vector<int>& V, int S) {
//     m_rslt = 0;
//     m_V = V;
//     solve(0, S);
//     return m_rslt;
//   }
// };

// iterative way
// O(N^2), O(N)
// 4ms 100.00%
class Solution {
 private:
  int solve(std::vector<int>& V, int tgt) {
    std::vector<int> C(tgt+1, 0);
    C[0] = 1;
    for (int n : V) {
      for (int i = tgt; i >= n; --i) {
        C[i] += C[i - n];
      }
    }
    return C[tgt];
  }
 public:
  int findTargetSumWays(std::vector<int>& V, int S) {
    int sum = std::accumulate(V.begin(), V.end(), 0, std::plus<int>());
    if (sum < S || (sum + S) % 2 > 0)
      return 0;
    return solve(V, (sum + S) / 2);
  }
};

int main() {

  std::vector<int> V = {1, 1, 1, 1, 1};
  Solution sln;
  printf("%d\n", sln.findTargetSumWays(V, 3));
  
  return 0;
}
