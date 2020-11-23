/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 260ms 55.19% 20MB 63.49%
class Solution {
 public:
  vector<string> maxNumOfSubstrings(string s) {
    int n = s.size();
    vector<int> fst(26, INT_MAX);
    vector<int> lst(26, INT_MIN);
    for (int i = 0; i < n; ++i) {
      int u = s[i]-'a';
      fst[u] = min(fst[u], i);
      lst[u] = max(lst[u], i);
    }
    vector<pair<int, int>> events;
    for (int i = 0; i < 26; ++i) {
      if (fst[i] < n) {
        int beg = fst[i];
        int end = lst[i];
        for (int j = beg; j <= end; ++j) {
          beg = min(beg, fst[s[j]-'a']);
          end = max(end, lst[s[j]-'a']);
        }
        if (beg == fst[i]) {
          events.emplace_back(end, beg);
        }
      }
    }
    sort(events.begin(), events.end());
    vector<string> ans;
    int prev = -1;
    for (auto& pr : events) {
      int end = pr.first;
      int beg = pr.second;
      if (beg > prev) {
        ans.push_back(s.substr(beg, end-beg+1));
        prev = end;
      }
    }
    return ans;
  }
};
