/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <cstdlib>

//      k: 1
//    pos: 1 3 2

//             l   r
//    day: 1 3 2
//               i
// minday: 2

// 196ms 87.79% 19.6MB 80.75%
// O(N) O(N)
class Solution {
 public:
  int kEmptySlots(std::vector<int>& pos, int k) {
    int n = pos.size();
    std::vector<int> day(n);  // day[i]: day of position i
    for (int i = 0; i < n; ++i)
      day[pos[i]-1] = i + 1;
    int l = 0;
    int r = k + 1;
    int minday = INT_MAX;
    for (int i = 1; r < n; ++i) {
      // printf("l: %d, r: %d, i: %d, minday: %d\n", l, r, i, minday);
      if (day[i] < day[l] || day[i] <= day[r]) {
        // jump
        if (i == r)
          minday = std::min(minday, std::max(day[l], day[r]));
        l = i;
        r = l + k + 1;
      }
    }
    return minday == INT_MAX ? -1 : minday;
  }
};

int main() {

  // std::vector<int> pos = {1, 3, 2};
  // int k = 1;
  std::vector<int> pos = {6, 5, 8, 9, 7, 1, 10, 2, 3, 4};
  int k = 2;

  Solution sln;
  printf("%d\n", sln.kEmptySlots(pos, k));
  
  return 0;
}
