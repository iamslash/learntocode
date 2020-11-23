/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

void printstep(int step) {
  for (int i = 0; i < step; ++i)
    printf("_");
}

// // recursive way
// // 0ms 100%
// class Solution {
//  private:
//   std::vector<int> m_C;
//   std::vector<int> m_V;
//   int solve(int tgt) {
//     // printstep(idx);
//     // printf("i:%d, t:%d\n", idx, tgt);

//     // memo
//     int& r = m_C[tgt];
//     if (r != -1)
//       return r;

//     // recursion
//     r = 0;
//     for (int i = 0; i < m_V.size(); ++i) {
//       if (tgt >= m_V[i]) {
//         r += solve(tgt - m_V[i]);
//       }
//     }
//     // printstep(idx);
//     // printf("r:%d\n", r);

//     return r;
//   }
//  public:
//   int combinationSum4(std::vector<int>& V, int t) {
//     if (V.empty() || t == 0)
//       return 0;
//     m_V = V;
//     m_C.resize(t+1, -1);
//     m_C[0] = 1;
//     return solve(t);
//   }
// };

// iterative way
// 0ms 100%
class Solution {
 public:
  int combinationSum4(std::vector<int>& V, int tgt) {
    std::vector<int> C(tgt+1);
    C[0] = 1;
    for (int i = 1; i <= tgt; ++i) {
      for (int j = 0; j < V.size(); ++j) {
        if (i - V[j] >= 0)
          C[i] += C[i-V[j]];
      }
    }
    return C[tgt];
  }
};

int main() {
  std::vector<int> V = {1, 2, 3};
  int t = 4;

  Solution sln;
  printf("%d\n", sln.combinationSum4(V, t));
  
  return 0;
}
