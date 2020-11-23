/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// tortoise and the hare algorithm by floyd
// 0ms 100.00% 8.2MB 68.15%
// O(N) O(1)
class Solution {
 private:
  int sqsum(int n) {
    int sum = 0;
    while (n) {
      int i = n % 10;
      sum += i * i;
      n /= 10;
    }
    return sum;
  }
 public:
  bool isHappy(int n) {
    int slow = sqsum(n);
    int fast = sqsum(sqsum(n));
    while (slow != fast) {
      slow = sqsum(slow);
      fast = sqsum(sqsum(fast));
      // printf("%d %d\n", slow, fast);
      if (slow == 1 || fast == 1)
        slow = fast = 1;
    }
    return slow == 1 ? true : false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Solution sln;
  printb(sln.isHappy(19));
  printb(sln.isHappy(1));
  
  return 0;
}
