/* Copyright (C) 2026 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 8.69MB 98.96%
// linear traversal
// O(N) O(1)
class Solution {
public:
  string reversePrefix(string s, int k) {
    int n = s.size();
    int h = k / 2;

    for (int i = 0; i < h; ++i) {
      char t = s[i];
      s[i] = s[k - i - 1];
      s[k - i - 1] = t;
    }

    return s;
  }
};

int main() {
  return 0;
}
