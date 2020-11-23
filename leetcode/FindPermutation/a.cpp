/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>

// 60ms 95.51% 11.6MB 22.22%
// two pointers
// O(N) O(1)
class Solution {
 public:
  std::vector<int> findPermutation(std::string s) {
    std::vector<int> rslt;
    int n = s.size();
    for (int i = 0; i <= n; ++i) {
      if (i == n || s[i] == 'I') {
        for (int j = i + 1, b = rslt.size(); j > b; --j)
          rslt.push_back(j);
      }
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  auto r = sln.findPermutation("IID");
  for (int a : r)
    printf("%d ", a);
  printf("\n");

  return 0;
}
