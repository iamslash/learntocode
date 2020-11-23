/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// zero  two
// six seven eight
// one three four five nine
//
// 0:  zero: z
// 2:   two: w
// 4:  four: u
// 6:   six: x
// 8: eight: g

// 1:   one: o: c[1]-=c[0]-c[2]-c[4]
// 3: three: h: c[3]-=c[8]
// 5:  five: f: c[5]-=c[4]
// 7: seven: s: c[7]-=c[6]
// 9:  nine: i: c[9]-=c[6]-c[8]-c[5]
//
// 44ms 2.68%
// class Solution {
//  public:
//   std::string originalDigits(std::string s) {
//     std::vector<int> cnt(10, 0);
//     for (char c : s) {
//       if (c == 'z') cnt[0]++;
//       if (c == 'w') cnt[2]++;
//       if (c == 'u') cnt[4]++;
//       if (c == 'x') cnt[6]++;
//       if (c == 'g') cnt[8]++;
//       if (c == 'o') cnt[1]++;
//       if (c == 'h') cnt[3]++;
//       if (c == 'f') cnt[5]++;
//       if (c == 's') cnt[7]++;
//       if (c == 'i') cnt[9]++;
//     }
//     // subtracts
//     cnt[1] -= cnt[0] + cnt[2] + cnt[4];
//     cnt[3] -= cnt[8];
//     cnt[5] -= cnt[4];
//     cnt[7] -= cnt[6];
//     cnt[9] -= cnt[6] + cnt[8] + cnt[5];
//     std::string rslt;
//     for (int i = 0; i < cnt.size(); ++i) {
//       for (int j = 0; j < cnt[i]; ++j)
//         rslt += std::to_string(i);
//     }
//     return rslt;
//   }
// };

//
// 12ms 98.66%
class Solution {
 public:
  std::string originalDigits(std::string s) {
    std::string rslt;
    std::vector<int> cnt(26, 0), dgt(10, 0);
    for (char c : s)
      ++cnt[c - 'a'];
    dgt[0] = cnt['z'-'a'];
    dgt[2] = cnt['w'-'a'];
    dgt[4] = cnt['u'-'a'];
    dgt[6] = cnt['x'-'a'];
    dgt[8] = cnt['g'-'a'];
    dgt[1] = cnt['o'-'a'] - dgt[0] - dgt[2] - dgt[4];
    dgt[3] = cnt['h'-'a'] - dgt[8];
    dgt[5] = cnt['f'-'a'] - dgt[4];
    dgt[7] = cnt['s'-'a'] - dgt[6];
    dgt[9] = cnt['i'-'a'] - dgt[6] - dgt[8] - dgt[5];
    for (int i = 0; i < 10; ++i)
      rslt += std::string(dgt[i], '0' + i);
    return rslt;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.originalDigits("owoztneoer").c_str());
  printf("%s\n", sln.originalDigits("fviefuro").c_str());
  
  return 0;
}
