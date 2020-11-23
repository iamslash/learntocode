/* Copyright (C) 2019 by iamslash */

#include <cstdio>

// "leetcode"
// 5

// 4ms 100.00% 8.5MB 39.53%
// Q. what is the range of n?
// O(N) O(1)

// Forward declaration of the read4 API.
int read4(char *buf);
class Solution {
public:
  int read(char *buf, int n) {
    int i = 0;
    while (i < n) {
      if (n - i >= 4) {
        int a = read4(buf + i);
        i += a;
        if (a < 4)
          return i;
      } else {
        char buf2[4] = {0,};
        int b = read4(buf2);
        int o = std::min(n - i, b);
        for (int j = 0; j < o; ++j)
          buf[i+j] = buf2[j];
        i += o;
        return i;
      }
    }
    return i;
  }
};

int main() { 
 
  return 0;
}
