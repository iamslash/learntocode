/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

//      i
// N: 1 0 0
//          j
// D: 1 3 5

// 4ms 51.84% 8.3MB 37.14%
// math
// O(DN) O(1)
class Solution {
 public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    string bound = to_string(N);
    int boundSize = bound.size(), digitSize = D.size(), ans = 0;
    // numbers whose size is lesser than bound string
    for (int i = 1; i < boundSize; ++i)
      ans += pow(digitSize, i);
    // numbers whose size is same with bound string
    for (int i = 0; i < boundSize; ++i) {
      bool bSameSum = false;
      for (string& d : D) {
        if (d[0] < bound[i]) {
          ans += pow(digitSize, boundSize - i - 1);
        } else if (d[0] == bound[i]) {
          bSameSum = true;
        }
      }
      if (bSameSum == false)
        return ans;
    }

    return ans + 1;
  }
};
