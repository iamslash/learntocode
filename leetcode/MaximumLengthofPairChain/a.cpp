/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>


// {-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}

// 64ms 100.00% 18.6MB 100.00%
// greedy
// O(NlgN) O(1)
class Solution {
 public:
  int findLongestChain(std::vector<std::vector<int>>& P) {
    std::sort(P.begin(), P.end(), [](const std::vector<int>& a,
                                     const std::vector<int>& b) {
                                    return a[1] == b[1] ?
                                        a[0] < b[0] :
                                        a[1] < b[1];
                                  });
    int cnt = 0;
    auto& prev = P[0];
    for (int i = 0; i < P.size(); ++i) {
      if (i == 0 || P[i][0] > prev[1]) {
        prev = P[i];
        cnt++;
      }
    }

    return cnt;
  }
};

int main() {

  // std::vector<std::vector<int>> P = {{1,2}, {2,3}, {3,4}};
  std::vector<std::vector<int>> P = {{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
  Solution sln;
  printf("%d\n", sln.findLongestChain(P));
  
  return 0;
}
