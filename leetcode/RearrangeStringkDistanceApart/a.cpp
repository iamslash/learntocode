/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

// s: aabbcc
// k: 3

// 48ms 79.70% 15.2MB 68.00%
// priority queue
// O(N) O(1)
class Solution {
 public:
  std::string rearrangeString(std::string s, int k) {
    if (k == 0)
      return s;
    std::vector<int> chr2cnt(26, 0);
    std::priority_queue<std::pair<int, char>> pq;
    int n = s.size();
    for (int i = 0; i < s.size(); ++i)
      chr2cnt[s[i]-'a']++;
    for (int i = 0; i < chr2cnt.size(); ++i)
      if (chr2cnt[i])
        pq.push({chr2cnt[i], i+'a'});
    std::string rslt;
    while (pq.size()) {
      std::vector<std::pair<int, char>> lost;
      int bnd = std::min(k, n);
      for (int i = 0; i < bnd; ++i) {
        if (pq.empty())
          return "";
        auto pr = pq.top(); pq.pop();
        rslt += pr.second;
        if (--pr.first > 0)
          lost.push_back(pr);
        --n;
      }
      for (auto& pr : lost)
        pq.push(pr);
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.rearrangeString("aabbcc", 3).c_str());
  printf("%s\n", sln.rearrangeString("", 3).c_str());
  printf("%s\n", sln.rearrangeString("aaabc", 3).c_str());
  printf("%s\n", sln.rearrangeString("aaadbbcc", 2).c_str());
  printf("%s\n", sln.rearrangeString("a", 0).c_str());
  printf("%s\n", sln.rearrangeString("a", 2).c_str());
  return 0;
}
