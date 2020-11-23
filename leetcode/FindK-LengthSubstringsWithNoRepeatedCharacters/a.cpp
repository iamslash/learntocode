/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// K: 5
//       i   j
// S: havefunonleetcode

// 4ms 92.41% 8.7MB 87.50%
// brute force
// O(N) O(1)
class Solution {
 public:
  int numKLenSubstrNoRepeats(std::string S, int K) {
    std::vector<int> cnts(26);
    int i = 0, j = 0, n = S.size(), ans = 0, unicnt = 0;
    while (j < n) {
      if (j - i == K) {
        if (--cnts[S[i]-'a'] == 0)
          --unicnt;
        ++i;
      }
      if (cnts[S[j]-'a']++ == 0)
        ++unicnt;
      ++j;
      if (unicnt == K)
        ++ans;
    }
    return ans;
  }
};

int main() {
  return 0;
}
