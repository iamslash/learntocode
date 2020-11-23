/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <climits>
#include <cmath>

// 36ms 32.73% 14.1MB 100.00%
// O(N) O(1)
class Solution {
 private:
  int getDist(std::vector<int>& s, std::vector<int>& d) {
    return std::abs(s[0] - d[0]) + std::abs(s[1] - d[1]);
  }
 public:
  int minDistance(int h, int w, std::vector<int>& tr,
                  std::vector<int>& sq,
                  std::vector<std::vector<int>>& nuts) {
    int maxd = INT_MIN;
    int totd = 0;
    for (auto& nt : nuts) {
      int n2td = getDist(nt, tr);
      int n2qd = getDist(nt, sq);
      totd += 2 * n2td;
      maxd = std::max(maxd, n2td - n2qd);
    }
    // maxd = dist(nut, tree) - dist(nut, squirrel)
    return totd - maxd;
  }
};

int main() {
  // int h = 5;
  // int w = 7;
  // std::vector<int> tr = {2, 2};
  // std::vector<int> sq = {4, 4};
  // std::vector<std::vector<int>> nuts = {
  //   {3, 0},
  //   {2, 5}
  // };
      
  int h = 5;
  int w = 5;
  std::vector<int> tr = {3, 2};
  std::vector<int> sq = {0, 1};
  std::vector<std::vector<int>> nuts = {
    {2,0},{4,1},{0,4},{1,3},{1,0},
    {3,4},{3,0},{2,3},{0,2},{0,0},
    {2,2},{4,2},{3,3},{4,4},{4,0},
    {4,3},{3,1},{2,1},{1,4},{2,4}
  };  
  Solution sln;
  printf("%d\n", sln.minDistance(h, w, tr, sq, nuts));
  
  return 0;
}
