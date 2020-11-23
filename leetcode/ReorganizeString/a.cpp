/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <queue>

// a a a b
// a b a a

// Q. s is just consted of lowercase letters?
// Q. what is the range of s.size()?
// 12ms 8.30% 8.9MB 73.49%
// greedy
// O(NlgN) O(1)
class Solution {
 public:
  std::string reorganizeString(std::string s) {
    std::vector<int> V(26, 0);
    std::priority_queue<std::pair<int, int>> pq;
    for (char c : s)
      V[c-'a']++;
    for (int i = 0; i < 26; ++i)
      if (V[i])
        pq.push({V[i], i + 'a'});
    std::string r;
    while(!pq.empty()) {
      auto pr1 = pq.top(); pq.pop();
      r.push_back(pr1.second);
      if (r.size() > 1 && *(r.rbegin()) == *(r.rbegin()+1))
        return "";
      if (!pq.empty()) {
        auto pr2 = pq.top(); pq.pop();
        r.push_back(pr2.second);
        if (r.size() > 1 && *(r.rbegin()) == *(r.rbegin()+1))
          return "";
        if (--pr2.first)
          pq.push(pr2);
      }
      if (--pr1.first)
        pq.push(pr1);
    }
    return r;
  }
};

int main() {
  std::string s = "aab";
  // std::string s = "aaab";
  Solution sln;
  printf("%s\n", sln.reorganizeString(s).c_str());  
  
  return 0;
}
