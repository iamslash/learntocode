/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/110/sorting-and-searching/803/

#include <cstdio>
#include <vector>
#include <algorithm>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// [[1,3],[2,6],[8,10],[15,18]]
//
// [1,3] [4,6]
// [1,3] [1,4]
// [1,3] [2,4]
// [1,3] [2,3]
//
class Solution {
 public:
  std::vector<Interval> merge(std::vector<Interval>& v) {
    std::vector<Interval> r;

    std::sort(v.begin(), v.end(),
              [](const Interval& a, const Interval& b) {
                return a.start < b.start;
              });
    for (auto& a : v) {
      if (r.empty() || r.back().end < a.start) {
        r.push_back(a);
      } else {
        Interval& b = r.back();
        b.start = std::min(b.start, a.start);
        b.end = std::max(b.end, a.end);
      }        
    }

    return r;
  }
};

int main() {
  std::vector<Interval> v = {
    {1, 3},
    {2, 6},
    {8, 10},
    {15,18}
  };
  
  Solution s;
  std::vector<Interval> r = s.merge(v);

  for (const auto& a : r) {
    printf("[%d, %d] ", a.start, a.end);
  }
  printf("\n");
  
  return 0;
}
