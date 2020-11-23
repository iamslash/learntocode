/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>


struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// [3,4] [2,3] [1,2]
// [1,2] [2,3] [3,4]

// 84ms 48.04%
class Solution {
 public:
  std::vector<int> findRightInterval(std::vector<Interval>& V) {
    std::vector<int> rslt;
    std::map<int, int> mp;  // start: index of V
    for (int i = 0; i < V.size(); ++i)
      mp[V[i].start] = i;
    for (const auto& v : V) {
      int idx = -1;
      auto it = mp.lower_bound(v.end);
      if (it != mp.end())
        idx = it->second;
      rslt.push_back(idx);
    }
    return rslt;
  }
};

int main() {
  std::vector<Interval> V = {
    {3, 4},
    {2, 3},
    {1, 2},
  };
  Solution sln;
  auto rslt = sln.findRightInterval(V);
  for (int a : rslt)
    printf("%d ", a);
  printf("\n");
  return 0;
}
