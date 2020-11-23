/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <algorithm>
#include <queue>

// 4ms 100.00% 8.4MB 93.75%
// Q. read4 fail can happen?
// Q. buf is always same?
// O(N) O(1)
int read4(char *buf);
class Solution {
 private:
  int i4 = 0;    // pointer of buf4
  int n4 = 0;    // nread of buf4
  char buf4[4];  // 
 public:
  int read(char *buf, int n) {
    int nread = 0;
    while (nread < n) {
      if (i4 == n4) {
        n4 = read4(buf4);
        i4 = 0;
        if (n4 == 0)
          break;
      }
      buf[nread++] = buf4[i4++];
    }
    return nread;
  }
};

int main() {
  Solution sln;
  sln.read(NULL, 3);
  return 0;
}
