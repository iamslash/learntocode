// Copyright (C) 2018 by iamslash

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
 public:
  int char2num(char c) {
    int rslt = 0;
    switch (c) {
      case 'A':
        rslt = 0;
      case 'C':
        rslt = 1;
      case 'G':
        rslt = 2;
      case 'T':
        rslt = 3;
    }
    return rslt;
  }
  std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    std::vector<std::string> rslt;
    if (s.size() <= 10)
      return rslt;
    std::unordered_map<int, int> M;  // M[number] = count
    int n = 0;
    for (int i = 0; i < 10; ++i) {
      n = (n << 2) | char2num(s[i]);
    }
    M[n] = 1;
    for (int i = 10; i < s.size(); ++i) {
      n = ((n << 2) & 0xFFFFF) | char2num(s[i]);
      printf("i: %2d n: %d\n", i, n);
      if (M.count(n) == 0) {
        M[n] = 1;
      } else if (M.count(n) == 1) {
        rslt.push_back(s.substr(i - 10, 10));
        M[n]++;
      } else {
        M[n]++;
      }
    }
    return rslt;
  }
};

int main() {
  std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";

  Solution sln;
  auto rslt = sln.findRepeatedDnaSequences(s);
  // for (const auto& a : rslt) {
  //   printf("%s\n", a.c_str());
  // }
  // printf("\n");
  return 0;
}
