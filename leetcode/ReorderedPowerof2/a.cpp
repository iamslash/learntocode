/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cmath>

// // 4ms 87.08% 8.4MB 60.00%
// // O(1) O(1)
// class Solution {
//  private:
//   bool isMatch(int a, int b) {
//     // count digit
//     std::vector<int> cnts(10, 0);
//     while (a > 0) {
//       cnts[a % 10]++;
//       a /= 10;
//     }
//     while (b > 0) {
//       cnts[b % 10]--;
//       b /= 10;
//     }
//     return std::all_of(cnts.begin(), cnts.end(), [](int i){return i == 0;});
//   }
//  public:
//   bool reorderedPowerOf2(int N) {
//     // 1 2 4 8 16
//     for (int i = 0; i <= 30; ++i) {
//       if (isMatch(1 << i, N))
//         return true;
//     }
//     return false;
//   }
// };

// 4ms 87.08% 8.1MB 88.48%
// O(1) O(1)
class Solution {
 private:
  int64_t getSum(int n) {
    int64_t r = 0;
    while (n) {
      r += std::pow(10, n % 10);
      n /= 10;
    }
    return r;
  }
 public:
  bool reorderedPowerOf2(int N) {
    int64_t sum = getSum(N);
    for (int i = 0; i < 31; ++i) {
      if (getSum(1 << i) == sum)
        return true;
    }
    return false;
  }  
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {  

  Solution sln;
  printb(sln.reorderedPowerOf2(1));
  printb(sln.reorderedPowerOf2(10));
  printb(sln.reorderedPowerOf2(16));
  printb(sln.reorderedPowerOf2(24));
  printb(sln.reorderedPowerOf2(46));
  
  return 0;
}
