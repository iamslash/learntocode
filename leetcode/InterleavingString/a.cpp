/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// aadbbcbcac

//   0 d b b c a
// 0 T F F F F F
// a T F F F F F
// a T T T T T F
// b F T T F T F
// c F F T T T T
// c F F F T F T

// cbb
//
//   0 d b
// 0 T F F
// b F F F

// 9ms 87.50%
// 4.4MB 3.12%
// O(HW) O(W)
class Solution {
 public:
  bool isInterleave(std::string s1, std::string s2, std::string s3) {
    int h = s2.size();
    int w = s1.size();
    if (h + w != s3.size())
      return false;
    std::vector<bool> C(w+1, true);

    for (int x = 1; x <= w; ++x) {
      C[x] = s1[x-1] == s3[x-1] && C[x-1];
    }
    for (int y = 1; y <= h; ++y) {
      C[0] = s2[y-1] == s3[y-1] && C[0];
      for (int x = 1; x <= w; ++x) {
        C[x] = (s3[y+x-1] == s1[x-1] && C[x-1]) || (s3[y+x-1] == s2[y-1] && C[x]);
      }
    }
    return C[w];
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  Solution sln;
  printb(sln.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
  // printb(sln.isInterleave("aabcc", "dbbca", "aadbbbaccc"));
  // printb(sln.isInterleave("db", "b", "cbb"));

  return 0;
}
