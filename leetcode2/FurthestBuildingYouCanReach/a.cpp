/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

//       H: 4 2 7 6 9 14 12
//                  i
//      pq: 3
//  bricks: 0
// ladders: 0

// 152ms 87.26% 46.1MB 10.36%
// greedy approach
// O(NlgN) O(N)
class Solution {
 public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    int usedBrickCnt = 0;
    priority_queue<int> usedBrickPq;
    int i = 0;
    for (i = 0; i < n-1; ++i) {
      if (heights[i] >= heights[i+1]) {
        continue;
      }
      int diff = heights[i+1] - heights[i];
      if (usedBrickCnt + diff <= bricks) {
        usedBrickCnt += diff;
        usedBrickPq.push(diff);
      } else if (ladders > 0) {
        if (!usedBrickPq.empty() &&
            usedBrickPq.top() > diff) {
          usedBrickCnt = usedBrickCnt -
              usedBrickPq.top() + diff;
          usedBrickPq.pop();
          usedBrickPq.push(diff);
        }
        ladders--;
      } else {
        break;
      }      
    }
    return i;
  }
};
