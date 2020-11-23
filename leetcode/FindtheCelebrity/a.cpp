/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// 68ms 96.41% 11.7MB 97.12%
// O(N) O(1)
bool knows(int a, int b);
class Solution {
 public:
  int findCelebrity(int n) {
    // candidate
    int u = 0;
    for (int i = 1; i < n; ++i)
      if (knows(u, i))
        u = i;
    for (int i = 0; i < n; ++i) {
      if (u == i)
        continue;
      if (!knows(i, u) || knows(u, i))
        return -1;
    }
    return u;
  }
};

int main() {
  return 0;
}
