/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <algorithm>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

//                    i
//              j
// [1,2] [1,3] [2,3] [3,4]
// 12ms 22.78%
class Solution {
 public:
  int eraseOverlapIntervals(std::vector<Interval>& V) {
    if (V.empty())
      return 0;
    std::sort(V.begin(), V.end(),
              [](const Interval& a, const Interval& b) {
                return a.start < b.start;
              });
    int rslt = 0;
    for (int i = 1, j = 0; i < V.size(); ++i) {
      if (V[i].start < V[j].end) {
        rslt++;
        if (V[i].end < V[j].end)
          j = i;
      } else {
        j = i;
      }
    }
    return rslt;
  }
};

int main() {

  // std::vector<Interval> V = {
  //   {1, 2},
  //   {2, 3},
  //   {3, 4},
  //   {1, 3},
  // };

  // std::vector<Interval> V = {
  //   {1, 2},
  //   {1, 2},
  //   {1, 2},
  // };

  std::vector<Interval> V = {
    {1, 2},
    {2, 3},
  };

  Solution sln;
  printf("%d\n", sln.eraseOverlapIntervals(V));
  
  return 0;
}
