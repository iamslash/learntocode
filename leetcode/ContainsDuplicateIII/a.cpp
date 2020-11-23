/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <set>
#include <limits>
#include <cstdint>


//   i
// 1 0 1 1
//
// w 1
// k 1
// t 2
//
// 12ms 86.80%
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(const std::vector<int>& V, int k, int t) {
    std::set<int64_t> wnd;
    for (int i = 0; i < V.size(); ++i) {
      // keep wnd's size is k
      if (i > k)
        wnd.erase(V[i-k-1]);
      // x = *pos
      // |x - V[i]| <= t
      // -t <= x - V[i] <= t
      //   x - V[i] >= -t
      //     x >= V[i] - t : use lower_bound
      //   x - V[i] <= t
      auto pos = wnd.lower_bound((int64_t)V[i] - t);
      if (pos != wnd.end() && *pos - V[i] <= t)
        return true;
      wnd.insert(V[i]);
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {
  std::vector<int> V1 = {1, 2, 3, 1};
  std::vector<int> V2 = {1, 0, 1, 1};
  std::vector<int> V3 = {1, 5, 9, 1, 5, 9};
  std::vector<int> V4 = {2147483647,-2147483647};
                         
  Solution sln;
  // printb(sln.containsNearbyAlmostDuplicate(V1, 3, 0));
  printb(sln.containsNearbyAlmostDuplicate(V2, 1, 2));
  // printb(sln.containsNearbyAlmostDuplicate(V3, 2, 3));
  // printb(sln.containsNearbyAlmostDuplicate(V4, 1, 2147483647));
  
  return 0;
}
