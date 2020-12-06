/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

//          k: 3
//             i
// cardPoints: 1 2 3 4 5 6 1
//                     j

// 144ms 9.71% 42.6MB 89.34%
// two pointers
// O(N) O(1)
class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size(), i = 0, j = n-k;
    int sum = accumulate(cardPoints.begin()+j, cardPoints.end(), 0);
    int ans = sum;
    while (k-- > 0) {
      sum += cardPoints[i++] - cardPoints[j++];
      ans = max(ans, sum);
    }
    return ans;
  }
};
