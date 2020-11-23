/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

// // 76ms 76.32% 21.5MB 52.73%
// // greedy
// // O(SA) O(S)
// // A: S[i].size()
// class Solution {
//  public:
//   std::vector<Interval> employeeFreeTime(
//       std::vector<std::vector<Interval>>& S) {
//     std::vector<Interval> rslt;
//     std::map<int, int> times;
//     int n = S.size();
//     for (int i = 0; i < n; ++i) {
//       for (int j = 0; j < S[i].size(); ++j) {
//         times[S[i][j].start]++;
//         times[S[i][j].end]--;
//       }
//     }
//     int prv = -1, cnt = 0;
//     for (auto& pr : times) {
//       if (cnt == 0 && prv >= 0)
//         rslt.push_back(Interval(prv, pr.first));
//       cnt += pr.second;
//       prv  = pr.first;
//     }
//     return rslt;
//   }
// };

// 68ms 100.00% 20.5MB 94.55%
// O(NlgN) O(N)
class Solution {
 private:
  struct cmp {
    bool operator()(const Interval& a, const Interval& b) {
      return a.start < b.start;
    }
  };
 public:
  std::vector<Interval> employeeFreeTime(
      std::vector<std::vector<Interval>>& S) {
    std::vector<Interval> rslt;
    std::vector<Interval> spans;
    for (auto& l : S)
      spans.insert(spans.end(), l.begin(), l.end());
    std::sort(spans.begin(), spans.end(), cmp());
    Interval last = spans[0];
    for (int i = 1; i < spans.size(); ++i) {
      auto& span = spans[i];
      if (span.start <= last.end) {
        last.end = std::max(span.end, last.end);
      } else {
        rslt.push_back(Interval(last.end, span.start));
        last = span;
      }
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<Interval>> S = {{{1,2},{5,6}},{{1,3}},{{4,10}}};

  Solution sln;
  auto r = sln.employeeFreeTime(S);

  for (auto& pr : r)
    printf("(%d, %d)", pr.start, pr.end);
  
  printf("\n");
  
  return 0;
}
