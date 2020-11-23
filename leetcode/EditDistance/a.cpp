/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

void printv(const std::vector<int> V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

// 8ms 78.62%
// 770KB 96.69%
// dynamic programming
// O(MN) O(N)
class Solution {
 public:
  int minDistance(std::string a, std::string b) {
    int M = a.size();
    int N = b.size();
    std::vector<int> C(N+1, 0);
    int pc = 0;  // prior cache
    for (int j = 1; j <= N; ++j) {
      C[j] = j;
    }
    // printv(C);
    for (int i = 1; i <= M; ++i) {
      C[0] = i;
      pc = i-1;
      for (int j = 1; j <= N; ++j) {
        int t = C[j];
        C[j] = a[i-1] == b[j-1] ?
            pc :
            std::min(C[j-1], std::min(pc, C[j])) + 1;
        pc = t;
      }
      // printv(C);
    }
    return C[N];
  }
};

//     r o s
//   0 1 2 3   0 1 2 3
// h 1 1 2 3   1 1 2 3
// o 2 2 1 2   2 2 1
// r 3 2 2 2
// s 4 3 3 2
// e 5 4 4 3


int main() {
  Solution sln;
  printf("%d\n", sln.minDistance("horse", "ros"));
  
  return 0;
}
