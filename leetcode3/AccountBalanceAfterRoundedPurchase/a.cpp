/* Copyright (C) 2023 by iamslash */

#include <cstdio>
#include <cmath>

using namespace std;

// 2ms 42.86% 6MB 57.14%
class Solution {
public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    double amt = purchaseAmount * 0.1;
    return 100 - round(amt) * 10;
  }
};

// 3ms 42.86% 6MB 57.14%
class Solution {
public:
  int accountBalanceAfterPurchase(int purchaseAmount) {
    if (purchaseAmount % 10) {
      int digit = purchaseAmount % 10;
      if (purchaseAmount % 10 < 5) {        
        purchaseAmount -= digit;
      } else {
        purchaseAmount += 10 - digit;
      }
    }
    return 100 - purchaseAmount;
  }
};

int main() {
  return 0;
}
