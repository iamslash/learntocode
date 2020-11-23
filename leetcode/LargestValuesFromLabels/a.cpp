/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <map>
#include <unordered_map>
#include <vector>

// 40ms 59.60% 14.5MB 100.00%
// greedy
// O(NlgN) O(N)
class Solution {
 public:
  int largestValsFromLabels(std::vector<int>& V,
                            std::vector<int>& L,
                            int wanted, int limit) {
    std::multimap<int, int> val2lbl;
    std::unordered_map<int, int> lbl2cnt;
    int n = V.size(), ans = 0;
    for (int i = 0; i < n; ++i)
      val2lbl.insert({V[i], L[i]});
    for (auto it = val2lbl.rbegin(); it != val2lbl.rend(); ++it) {
      int lbl = it->second;
      if (++lbl2cnt[lbl] <= limit)
        ans += it->first, --wanted;
      if (wanted <= 0)
        break;
    }
    return ans;
  }
};

int main() {
  return 0;
}
