/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// {a,b}{c,{d,e}}

// 24ms 89.07% 12.8MB 100.00%
// DFS
class Solution {
 private:
  void crossjoin(unordered_set<string> &a,
                 unordered_set<string> &b) {
    if (a.size() == 0) {
      a = b;
      return;
    }
    if (b.size() == 0)
      return;
    unordered_set<string> c = a;
    a.clear();
    for (auto &s : c) {
      for (auto &t : b) {
        a.insert(s + t);
      }
    }
  }
  void addrange(unordered_set<string> &a,
                unordered_set<string> &b) {
    for (auto& s : b)
      a.insert(s);
  }
  unordered_set<string> dfs(string &expr, int &i) {
    unordered_set<string> ans;
    while (i < expr.size()) {
      char c = expr[i];
      if (c == ',') {
        auto tmp = dfs(expr, ++i);
        addrange(ans, tmp);
      } else if (c == '{') {
        auto tmp = dfs(expr, ++i);
        ++i;
        crossjoin(ans, tmp);
      } else if (c == '}') {
        return ans;
      } else {
        string s;
        while (i < expr.size() &&
               expr[i] >= 'a' &&
               expr[i] <= 'z') {
          s += expr[i++];
        }
        unordered_set<string> tmp = {s};
        crossjoin(ans, tmp);
      }
    }
    return ans;
  }
 public:
  vector<string> braceExpansionII(string expr) {
    int i = 0;
    auto tmp = dfs(expr, i);
    auto ans = vector<string>(tmp.begin(), tmp.end());
    sort(ans.begin(), ans.end());
    return ans;
  }
                 
};

int main() {
  return 0;
}
