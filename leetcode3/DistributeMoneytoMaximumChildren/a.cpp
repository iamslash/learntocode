/* Copyright (C) 2023 by iamslash */

#include <cstdio>

// 9ms 12.50% 5.8MB 100.00%
// greedy
// O(N) O(1)
class Solution {
public:
  int distMoney(int money, int children) {
    int cnt = 0;
    if (money - children < 0) {
      return -1;
    }
    if (money > children * 8) {
      return children - 1;
    }
    while (money > 0 && money - 8 >= children - 1) {
      cnt++;
      money -= 8;
      children--;
    }
    if (money == 4 && children == 1) {
      cnt--;
    }
    return cnt;
  }
};

int main() {
  return 0;
}
