/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 24ms 77.34% 7.3MB 94.92%
// greedy algorithm
// O(T^2S) O(T)
class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    int m = stamp.size(), n = target.size();
    auto matchFunc = [&](int i) {
                       int cntStar = 0;
                       for (int j = 0; j < m; ++j) {
                         if (target[i+j] != '*' &&
                             target[i+j] != stamp[j])
                           return false;
                         if (target[i+j] == '*')
                           cntStar++;
                       }
                       if (cntStar == stamp.size())
                         return false;
                       return true;
                     };
    vector<int> ans;
    string done(n, '*');
    while (target != done) {
      bool stamped = false;
      for (int i = 0; i < n - m + 1; ++i) {
        if (matchFunc(i)) {
          fill(target.begin() + i, target.begin() + i + m, '*');
          stamped = true;
          ans.push_back(i);
        }
      }
      if (!stamped)
        return {};
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
