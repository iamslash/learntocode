/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>

//                  i
// token: 100 200 300 400
//                  j
// power: 0
// point: 2

// greedy
// O(NlgN) O(1)
class Solution {
 public:
  int bagOfTokensScore(std::vector<int>& token, int power) {
    std::sort(token.begin(), token.end());
    int n = token.size(), i = 0, j = n-1, point = 0;
    while (i <= j) {
      if (token[i] <= power) {
        power -= token[i];
        ++i;
        ++point;
      } else if (i < j && point > 0) {
        power += token[j];
        --j;
        --point;
      } else {
        break;
      }
    }
    return point;
  }
};

int main() {
  return 0;
}
