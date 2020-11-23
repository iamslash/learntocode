/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

// // 48ms 75.13% 24.9MB 5.00%
// // O(N) O(N)
// class Solution {
//  public:
//   std::vector<std::string> findRepeatedDnaSequences(std::string s) {
//     std::unordered_map<std::string, int> seq2cnt;
//     std::unordered_set<std::string> seqs;
//     int n = s.size();
//     for (int i = 0; i <= n - 10; ++i) {
//       std::string seq = s.substr(i, 10);
//       if (seq2cnt.count(seq))
//         seqs.insert(seq);
//       seq2cnt[seq]++;
//     }
//     return std::vector<std::string>(seqs.begin(), seqs.end());
//   }
// };

// // 40ms 91.45% 16.9MB 73.66%
// // O(N) O(N)
// class Solution {
//  private:
//   int cha2num(char c) {
//     int r = 0;
//     switch (c) {
//       case 'C': r = 1; break;
//       case 'G': r = 2; break;
//       case 'T': r = 3; break;
//     }
//     return r;
//   }
//  public:
//   std::vector<std::string> findRepeatedDnaSequences(std::string s) {
//     int n = s.size();
//     if (n <= 10)
//       return {};
//     std::unordered_map<int, int> seq2cnt;
//     std::unordered_set<std::string> seqs;
//     int num = 0;
//     for (int i = 0; i < 10; ++i)
//       num = (num << 2) | cha2num(s[i]);
//     seq2cnt[num]++;
//     for (int i = 10; i < n; ++i) {
//       num = ((num << 2) & 0xFFFFF) | cha2num(s[i]);
//       if (seq2cnt.count(num))
//         seqs.insert(s.substr(i-9, 10));
//       seq2cnt[num]++;
//     }
//     return std::vector<std::string>(seqs.begin(), seqs.end());
//   }
// };

// 4ms 100.00% 9.6MB 97.53%
// O(N) O(N)
class Solution {
 public:
  std::vector<std::string> findRepeatedDnaSequences(std::string& s) {
    if (s.size() <= 10)
      return {};
    std::vector<std::string> rslt;
    std::bitset<0x100000> seen1, seen2;
    int num = 0;
    for (int i = 0; i < s.size(); ++i) {
      num <<= 2; num &= 0xFFFFF;
      switch (s[i]) {
        case 'C': num |= 0x01; break;
        case 'G': num |= 0x02; break;
        case 'T': num |= 0x03; break;
      }
      if (i >= 9) {
        if (seen1.test(num)) {
          if (!seen2.test(num))
            rslt.push_back(s.substr(i-9, 10));
          seen2.set(num);
        } else {
          seen1.set(num);
        }
      }
    }
    return rslt;
  }
};

int main() {
  return 0;
}
