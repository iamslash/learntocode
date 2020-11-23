/* Copyright (C) 2018 by iamslash */

#include <cstdio>

// 1
// 1
//
// 1 2
// 2
//
// 1 2 3
// 2
//
// 1 2 3 4
// 2 4
// 2
//
// 1 2 3 4 5
// 2 4
// 2
//
// 1 2 3 4 5 6
// 2 4 6
// 4
//
// 1 2 3 4 5 6 7
// 2 4 6
// 4
//
// 1 2 3 4 5 6 7 8
// 2 4 6 8
// 2 6
// 6
//
// 1 2 3 4 5 6 7 8 9
// 2 4 6 8
// 2 6
// 6
//
// ML(1...n) + MR(1...n) = 1 + n
//
// recursive way
// 52ms 40.04%
// class Solution {
//  public:
//   int lastRemaining(int n) {
//     return n == 1 ? 1 : 2 * (1 + n/2 - lastRemaining(n/2));
//   }
// };

// iterative way
// 56ms 29.18%
class Solution {
 public:
  int lastRemaining(int n) {
    bool left = true;
    int remain = n;  // remaining count
    int step = 1;
    int head = 1;
    while (remain > 1) {
      if (left || remain % 2 == 1)
        head += step;
      remain /= 2;
      step *= 2;
      left = !left;
    }
    return head;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.lastRemaining(9));
  return 0;
}
