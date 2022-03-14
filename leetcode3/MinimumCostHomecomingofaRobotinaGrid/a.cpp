/* Copyright (C) 2022 by iamslash */

#include <cstdio>
#include <vector>

using namespace std;

// 252ms 55.82% 149.9MB 26.89%
// matrix
// O(N) O(1)
class Solution {
public:
  int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
    int cost = 0, y = startPos[0], x = startPos[1], z = homePos[0], w = homePos[1];
    while (y != z) {
      y += (z - y) / abs(z - y);
      cost += rowCosts[y];
    }
    while (x != w) {
      x += (w - x) / abs(w - x);
      cost += colCosts[x];
    }
    return cost;
  }
};

int main() {
  return 0;
}
