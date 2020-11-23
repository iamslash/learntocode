/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// a x b c d x
// e x a x x x
// b c d x e x

// "a bcd e "
// 3
// 6

// 8ms 96.95% 8.9MB 98.46%
// O(HW) O(S)
class Solution {
 public:
  int wordsTyping(std::vector<std::string>& S, int h, int w) {
    std::string a;
    for (auto& s : S)
      a += s + " ";
    // i: index of a
    int i = 0, n = a.size();
    for (int y = 0; y < h; ++y) {
      i += w;
      if (a[i % n] == ' ') {
        i++;
      } else {
        while (i > 0 && a[(i-1)%n] != ' ')
          --i;
      }
    }
    return i / a.size();
  }
};

int main() {
  // int h = 2;
  // int w = 8;
  // std::vector<std::string> S = {"hello", "world"};
  // int h = 3;
  // int w = 6;
  // std::vector<std::string> S = {"a", "bcd", "e"};
  // int h = 8;
  // int w = 7;
  // std::vector<std::string> S = {"f", "p", "a"};
  int h = 20000;
  int w = 20000;
  std::vector<std::string> S = {"a"};
  Solution sln;
  printf("%d\n", sln.wordsTyping(S, h, w));
  
  return 0;
}
