/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// // 16ms 53.04% 10.1MB 5.77%
// // ab % k = (a%k)(b%k)%k
// // O(lgN) O(lgN)
// #define MOD 1337
// class Solution {
//  private:
//   int powk(int a, int k) {
//     a %= MOD;
//     int r = 1;
//     for (int i = 0; i < k; ++i)
//       r = (r * a) % MOD;
//     return r;
//   }
//  public:
//   int superPow(int a, std::vector<int>& b) {
//     if (b.empty())
//       return 1;
//     int k = b.back(); b.pop_back();
//     return powk(superPow(a, b), 10) * powk(a, k) % MOD;
//   }
// };

// 8ms 97.98% 10MB 10.58%
// O(lgN) O(lgN)
#define MOD 1337
class Solution {
 private:
  int powk(int a, int k) {
    // base
    if (k == 0)
      return 1;
    if (k == 1)
      return a % MOD;
    a %= MOD;
    int r = 1;
    while (k > 0) {
      if (k & 1)
        r = (r * a) % MOD;
      k /= 2;
      a = (a * a) % MOD;
    }
    return r;
  }
 public:
  int superPow(int a, std::vector<int>& b) {
    if (b.empty())
      return 1;
    int k = b.back(); b.pop_back();
    return powk(superPow(a, b), 10) * powk(a, k) % MOD;
  }
};

int main() {
  int n = 2;
  std::vector<int> V = {3};

  Solution sln;
  printf("%d\n", sln.superPow(n, V));
  
  return 0;
}
