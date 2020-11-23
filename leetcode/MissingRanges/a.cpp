/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

// 4ms 100.00% 8.5MB 35.00%
// O(N) O(N)
class Solution {
 private:
  std::string getRange(int64_t s, int64_t e) {
    std::string r = std::to_string(s);
    if (e > s)
      r += "->" + std::to_string(e);
    return r;
  }
 public:
  std::vector<std::string> findMissingRanges(
      std::vector<int>& V, int64_t lo, int64_t hi) {
    int s = std::lower_bound(V.begin(), V.end(), lo) - V.begin();
    int e = std::lower_bound(V.begin(), V.end(), hi) - V.begin();
    std::vector<std::string> rslt;
    int64_t prv = lo - 1;
    for (int i = s; i <= e; ++i) {
      int64_t cur = (i == V.size() ? hi + 1 : V[i]);
      if (cur - prv >= 2)
        rslt.push_back(getRange(prv+1, cur-1));
      prv = cur;
    }
    return rslt;
  }
};

int main() {

  std::vector<int> V = {0, 1, 3, 50, 75};
  // std::vector<int> V = {};
  int lo = 0, hi = 99;
  Solution sln;
  auto r = sln.findMissingRanges(V, lo, hi);
  for (auto& s : r)
    printf("%s ", s.c_str());
  printf("\n");
  
  return 0;
}
