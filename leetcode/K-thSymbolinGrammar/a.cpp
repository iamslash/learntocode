/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 0
// 01
// 0110
// 01101001
// 0110100110010110
// 01101001100101101001011001101001

// 4ms 100.00% 8.4MB 84.00%
// Q. what is the range of N? [1,30]
// Q. what is the range of K? [1,2^(N-1)]
// O(lgk) O(1)
class Solution {
 public:
  int kthGrammar(int n, int k) {
    int r = 0;
    while (k > 1) {
      k = (k % 2 == 1) ? k + 1 : k / 2;
      r ^= 1;
    }
    return r;    
  }
};

// 4ms 100.00% 8.6MB 28%
// O(lgN) O(1)
class Solution {
 public:
  int kthGrammar(int n, int k) {
    // base
    if (n == 1)
      return 0;
    
    // recursion
    if (k%2 == 0)
      return kthGrammar(n-1, k/2) == 0 ? 1 : 0;
    return kthGrammar(n-1, (k+1)/2) == 0 ? 0 : 1;
  }
};

int main() {
  return 0;
}
