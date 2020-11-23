#include <cstdio>
#include <vector>
#include <algorithm>

// 8ms 100.00% 9.6MB 100.00%
// dynamic programming
// O(N) O(1)
class Solution {
 public:
  int minCost(std::vector<std::vector<int>>& C) {
    int n = C.size();
    if (n == 0)
      return 0;
    int r = C[0][0];  // minimum price for red   at this time
    int g = C[0][1];  // minimum price for green at this time
    int b = C[0][2];  // minimum price for blue  at this time
    for (int i = 1; i < n; ++i) {
      int tr = C[i][0] + std::min(g, b);
      int tg = C[i][1] + std::min(r, b);
      int tb = C[i][2] + std::min(r, g);
      r = tr;
      g = tg;
      b = tb;
    }
    return std::min(r, std::min(g, b));  
  }
};

int main() {
  std::vector<std::vector<int>> C = {{17,2,17},{16,16,5},{14,3,19}};
  Solution sln;
  printf("%d\n", sln.minCost(C));
  return 0;
}