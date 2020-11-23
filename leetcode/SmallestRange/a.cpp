/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <queue>
#include <map>

// 64ms 100.00% 10.8MB 0.52%
// O(KNlgN) O(K)
typedef std::vector<int>::iterator IT;

class Comp {
 public:
  bool operator()(const std::pair<IT, IT>& a,
                  const std::pair<IT, IT>& b) {
    return *a.first > *b.first;
  }
};

class Solution {
 public:
  std::vector<int> smallestRange(std::vector<std::vector<int>>& LL) {
    std::priority_queue<std::pair<IT, IT>,
                        std::vector<std::pair<IT, IT>>, Comp> pq;  // (begin it, end it)
    int lo = INT_MAX, hi = INT_MIN;
    for (auto& L : LL) {
      lo = std::min(lo, L[0]);
      hi = std::max(hi, L[0]);
      pq.push({L.begin(), L.end()});
    }
    std::vector<int> rslt = {lo, hi};
    while (true) {
      auto item = pq.top(); pq.pop();
      ++(item.first);
      if (item.first == item.second)
        break;
      pq.push(item);

      lo = *pq.top().first;
      hi = std::max(hi, *item.first);
      if (hi - lo < rslt[1] - rslt[0])
        rslt = {lo, hi};
    }
    return rslt;
  }
};

int main() {
  std::vector<std::vector<int>> L = {
    {4,10,15,24,26},
    {0,9,12,20},
    {5,18,22,30}
  };

  Solution sln;
  auto r = sln.smallestRange(L);
  printf("%d %d\n", r[0], r[1]);
  
  return 0;
}
