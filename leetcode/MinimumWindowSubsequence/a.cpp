/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>

//   0 a b c d e b d d e
// 0 1 2 3 4 5 6 7 8 9 10
// b 0 0 2 2 2 2 6 6 6 6
// d 0 0 0 0 2 2 2 6 6 6
// e 0 0 0 0 0 2 2 2 2 6

//   0 c n h c z m c c q o u q a d q t m j j z l
// 0 1 2 3 4 5 6 7 8 9 10111213141516171819202122
// m 0 0 0 0 0 0 6 6 6 6 6 6 6 6 6 6 6 1717171717
// m 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 6 6 6 6 6

// 104ms 68.88% 11.8MB 62.58%
// dynamic programming
// O(HW) O(W)
class Solution {
 public:
  std::string minWindow(std::string S, std::string T) {
    int h = T.length(), w = S.length();
    std::vector<int> C (w+1);
    std::iota(C.begin(), C.end(), 1);
    for (int y = 1; y <= h; ++y) {
      int prv = C[0];
      C[0] = 0;
      for (int x = 1; x <= w; ++x) {
        int tmp = C[x];
        C[x] = T[y-1] == S[x-1] ? prv : C[x-1];
        prv = tmp;
      }
    }
    int beg = 0, len = w + 1;
    for (int x = 1; x <= w; x++) {
      if (C[x] == 0 || x - C[x] + 1 >= len)
        continue;
      beg = C[x] - 1;
      len = x - C[x] + 1;
    }
    return len == w + 1 ? "" : S.substr(beg, len);
  }
};

// // 120ms 61.90%
// // dynamic programming
// // O(HW) O(HW)
// class Solution {
//  public:
//   std::string minWindow(std::string S, std::string T) {
//     int h = T.length(), w = S.length();
//     std::vector<std::vector<int>> C(h+1, std::vector<int>(w+1, 0));
//     for (int x = 0; x <= w; x++) {
//       C[0][x] = x + 1;
//     }
//     for (int y = 1; y <= h; y++) {
//       for (int x = 1; x <= w; x++) {
//         C[y][x] = T[y-1] == S[x-1] ? C[y-1][x-1] : C[y][x-1];
//       }
//     }

//     int beg = 0, len = w + 1;
//     for (int x = 1; x <= w; x++) {
//       if (C[h][x] == 0 || x - C[h][x] + 1 >= len)
//         continue;
//       beg = C[h][x] - 1;
//       len = x - C[h][x] + 1;
//     }
//     return len == w + 1 ? "" : S.substr(beg, len);
//   }
// };

int main() {

  // std::string S = "abcdebdde";
  // std::string T = "bde";
  // std::string S = "wcbsuiyzacfgrqsqsnodwmxzkz";
  // std::string T = "xwqe";
  std::string S = "cnhczmccqouqadqtmjjzl";
  std::string T = "mm";
  
  Solution sln;  
  printf("%s\n", sln.minWindow(S, T).c_str());
  
  return 0;
}
