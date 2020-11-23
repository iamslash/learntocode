/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

// 8ms 59.21% 9.4MB 100.00%
// Math
// O(NlgN) O(N)
class Solution {
 public:
  int maximumNumberOfOnes(int w, int h, int sideLength, int maxOnes) {
    std::vector<int> rec;
    for (int i = 0; i < sideLength; ++i) {
      for (int j = 0; j < sideLength; ++j) {
        rec.push_back(
            ((w - i - 1) / sideLength + 1) *
            ((h - j - 1) / sideLength + 1));
      }
    }
    std::sort(rec.begin(), rec.end(), std::greater<int>());
    int ans = 0;
    for (int i = 0; i < maxOnes; ++i)
      ans += rec[i];
    return ans;
  }
};

int main() {
  return 0;
}
