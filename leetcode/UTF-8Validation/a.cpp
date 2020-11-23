/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>

// 16ms 29.93%
class Solution {
 private:
  
 public:
  bool validUtf8(std::vector<int>& V) {
    int n = V.size();
    for (int i = 0; i < n;) {
      if ((n - i >= 4) &&
          ((V[i] >> 3) == 0x1E) &&
          ((V[i+1] >> 6) == 0x02) &&
          ((V[i+2] >> 6) == 0x02) &&
          ((V[i+3] >> 6) == 0x02)) {
        i += 4;
      } else if ((n - i >= 3) &&
                 ((V[i] >> 4) == 0x0E) &&
                 ((V[i+1] >> 6) == 0x02) &&
                 ((V[i+2] >> 6) == 0x02)) {
        i += 3;
      } else if ((n - i >= 2) &&
                 ((V[i] >> 5) == 0x06) &&
                 ((V[i+1] >> 6) == 0x02)) {
        i += 2;
      } else if ((V[i] >> 7) == 0x00) {
        i++;
      } else {
        // printf("%d\n", i);
        return false;
      }
      // printf("%d\n", i);
    }

    return true;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<int> V0 = {197, 130, 1};
  std::vector<int> V1 = {235, 140, 4};

  Solution sln;
  printb(sln.validUtf8(V0));
  printb(sln.validUtf8(V1));

  // printb((197 & 0x80) == 0x80);
  // printf("0x%x 0x%x\n", 197 >> 5, 130 >> 6);
  
  return 0;
}
