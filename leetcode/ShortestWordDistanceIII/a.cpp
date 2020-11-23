/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <string>

// 20ms 64.04% 11.9MB 57.14%
// O(N) O(N)
class Solution {
 public:
  int shortestWordDistance(
      std::vector<std::string>& W, std::string a, std::string b) {
    int d = INT_MAX;
    int l = -1;
    int r = -1;
    for (int i = 0; i < W.size(); ++i) {
      if (a == W[i])
        l = i;
      if (b == W[i]) {
        if (a == b)
          l = r;
        r = i;
      }
      if (~l && ~r)
        d = std::min(d, std::abs(r - l));
    }
    return d;
  }
};

int main() {

  std::vector<std::string> W = {"practice", "makes", "perfect", "coding", "makes"};
  Solution sln;
  printf("%d\n", sln.shortestWordDistance(W, "makes", "coding"));
  printf("%d\n", sln.shortestWordDistance(W, "makes", "makes"));  
  return 0;
}
