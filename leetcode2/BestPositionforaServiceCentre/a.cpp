/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

// 32ms 63.04% 8.6MB 17.90%
// simulated annealing
// O(???) O(???)
class Solution {
 private:
  const int dirs[5] = {-1, 0, 1, 0, -1};
  double dist(vector<int>& a, vector<double>& b) {
    return sqrt(pow(a[0]-b[0],2) + pow(a[1]-b[1],2));
  }
  double distAll(vector<vector<int>>& A, vector<double>& c) {
    double ans = 0;
    for (auto& a : A) {
      ans += dist(a, c);
    }
    return ans;
  }
 public:
  double getMinDistSum(vector<vector<int>>& P) {
    double minCost = DBL_MAX;
    vector<double> centerPos(2, 0);
    double step = 100, epsilon = 1e-6;
    while (step > epsilon) {
      bool found = false;
      for (int i = 0; i < 4; ++i) {
        double nx = centerPos[0] + step * dirs[i];
        double ny = centerPos[1] + step * dirs[i+1];
        vector<double> nextCenter = {nx, ny};
        double cost = distAll(P, nextCenter);
        if (cost < minCost) {
          minCost = cost;
          centerPos = nextCenter;
          found = true;
          break;
        }
      }
      if (!found) {
        step /= 2;
      }
    }
    return minCost;
  }
};
