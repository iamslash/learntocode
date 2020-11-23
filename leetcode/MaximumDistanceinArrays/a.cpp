#include <cstdio>
#include <cstdlib>
#include <vector>

// 32ms 100.00% 16.8MB 100.0%
// Q. VV can be empty()??? two at least
// Q. VV[y] can be empty()??? one at least
// Q. what is the range of VV[y].size()??? [2, 10000]
// Q. what is the range of VV[y][x]??? [-10000, 10000]
// O(N) O(1)
class Solution {
 public:
  int maxDistance(std::vector<std::vector<int>>& VV) {
    int lminn = INT_MAX, lminy, lmaxn = INT_MIN;
    int rmaxn = INT_MIN, rmaxy, rminn = INT_MAX;
    for (int y = 0; y < VV.size(); ++y) {
      if (lminn > VV[y][0]) {
        lminn = VV[y][0];
        lminy = y;
      }
      if (rmaxn < VV[y].back()) {
        rmaxn = VV[y].back();
        rmaxy = y;
      }
    }
    for (int y = 0; y < VV.size(); ++y) {
      if (lminy != y && lmaxn < VV[y].back())
        lmaxn = VV[y].back();
      if (rmaxy != y && rminn > VV[y][0]) 
        rminn = VV[y][0];
    }
    return std::max(lmaxn-lminn, rmaxn-rminn);
  }
};

int main() {
  //std::vector<std::vector<int>> VV = {{1,2,3},{4,5},{1,2,3}};
  std::vector<std::vector<int>> VV = {{-2},{-3,-2,1}};
  Solution sln;
  printf("%d\n", sln.maxDistance(VV));
  return 0;
}
