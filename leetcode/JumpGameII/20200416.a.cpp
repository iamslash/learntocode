/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <limits>

//:0 1 2 3 4 5
// 2 3 1 1 4

//     i
// 0 1 1 2 2

// // 564ms 22.45%
// // O(N^2) O(N)
// class Solution {
//  private:
//   std::vector<int> m_N;
  
//  public:
//   int jump(std::vector<int>& N) {
//     int n = N.size();
//     std::vector<int> C(n, std::numeric_limits<int>::max());
//     C[0] = 0;
//     for (int i = 0; i < n; ++i) {
//       for (int j = i + 1; j <= i + N[i] && j < n; ++j) {
//         C[j] = std::min(C[j], C[i]+1);
//       }
//       // for (int j = 0; j < C.size(); ++j)
//       //   printf("%d ", C[j]);
//       // printf("\n");
//     }
//     return C[n-1];    
//   }
// };


// c
// 2 3 1 1 4

// 8ms 98.98%
// BFS
// O(N) O(1)
class Solution {
 public:
  int jump(std::vector<int>& N) {
    if (N.size() <= 1)
      return 0;
    int cur = 0;
    int end = N.size() - 1;
    int cnt = 0; // step
    while (cur + N[cur] < end) {
      int max = 0;
      for (int i = 1; i <= N[cur]; ++i) {
        if (N[cur + i] + i > N[cur + max] + max)
          max = i;
      }
      cur += max;
      ++cnt;
    }
    return ++cnt;
  }
};

int main() {

  std::vector<int> N = {2, 3, 1, 1, 4};

  Solution sln;
  printf("%d\n", sln.jump(N));
  
  return 0;
}
