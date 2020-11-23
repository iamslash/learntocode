/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <cstdint>

//   0 1 2 3
// 0 0 0 0 0
// 1 0 0 0 0
// 2 0 0 2 2
// 3 0 0 0 6  
//
// 8ms 91.30% 12MB 100.00%
// O(NL) O(NL)
class Solution {
 private:
  int64_t factorial(int n) {
    return n ? factorial(n - 1) * n % (int64_t)(1e9+7) : 1;
  }
 public:
  int numMusicPlaylists(int N, int L, int K) {
    int64_t mod = 1e9+7;
    std::vector<std::vector<int64_t>> C(N+1, std::vector<int64_t>(L+1, 0));
    for (int i = K+1; i <= N; ++i) {
      for (int j = i; j <= L; ++j) {
        if ((i == j) || (i == K + 1))
          C[i][j] = factorial(i);
        else
          C[i][j] = (C[i-1][j-1] * i + C[i][j-1]*(i-K)) % mod;
      }
    }

    for (auto& l : C) {
      for (int a : l)
        printf("%d ", a);
      printf("\n");
    }
    
    return C[N][L];
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.numMusicPlaylists(3, 3, 1));    // 6
  // printf("%d\n", sln.numMusicPlaylists(2, 3, 0)); // 6
  // printf("%d\n", sln.numMusicPlaylists(2, 3, 1)); // 2
  // printf("%d\n", sln.numMusicPlaylists(1, 1, 1));    // 1
  
  return 0;
}
