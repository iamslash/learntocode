/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <algorithm>

using namespace std;

//  
// a: 0 
// b: 1 

// 4ms 76.18% 5.9MB 90.89%
// fibonacci
// O(K) O(K)
class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    int a = 0, b = 1;
    while (b <= k) {
      swap(a, b);
      b += a;
    }
    if (a == k)
      return 1;
    return 1 + findMinFibonacciNumbers(k - a);
  }
};
