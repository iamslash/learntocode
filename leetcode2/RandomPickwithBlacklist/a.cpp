/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

//         N: 10
// blackList: 3 5 7 9
// 1 2 3 4 5 | 6 7 8 9
//     8   6
//  blackMap: 3 5 7 9
//            8 6 - -
// whitesize: 6

// 292ms 86.75% 71.2MB 45.37%
// pick: O(1) O(N)
class Solution {
 private:
  int whiteSize;
  unordered_map<int, int> blackMap;
 public:
  Solution(int N, vector<int>& blackList) {
    for (int b : blackList) {
      if (b < N) {
        blackMap[b] = -1;
      }
    }
    whiteSize = N - blackMap.size();
    for (int b : blackList) {
      if (b < whiteSize) {
        while (blackMap.count(--N)) {          
        }
        blackMap[b] = N;
      }
    }
  }    
  int pick() {
    int p = random() % whiteSize;
    if (blackMap.count(p))
      return blackMap[p];
    return p;
  }
};
