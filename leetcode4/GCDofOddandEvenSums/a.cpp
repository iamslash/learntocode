/* Copyright (C) 2025 by iamslash */

#include <cstdio>

// math
// O(1) O(1)
class Solution {

private:
  int gcd(int a, int b) {
    // base
    if (b == 0) {
      return a;
    }
    
    // recursion
    return gcd(b, a % b);
  }
  
public:
  int gcdOfOddEvenSums(int n) {
    int nn = n + n;
    int sum = nn * (nn + 1) / 2;

    int sum_odd = (sum - n);
    int sum_evn = sum_odd + n;

    return gcd(sum_evn, sum_odd);
  }
  
};

int main() {
  Solution sln;
  
  return sln.gcdOfOddEvenSums(10);
}
