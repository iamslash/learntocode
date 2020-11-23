/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 524ms 16.90% 11.7MB 53.69%
// sort
// O(NlgN) O(1)
class Solution {
 public:
  bool checkIfCanBreak(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool greaterA = true, greaterB = true;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] < b[i])
        greaterA = false;
      if (a[i] > b[i])
        greaterB = false;
    }
    return greaterA || greaterB;
  }
};
