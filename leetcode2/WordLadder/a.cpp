/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/118/trees-and-graphs/842/

#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>

#include <iostream>
static int _x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();
// BFS
class Solution {
 public:
  int ladderLength(std::string sb, std::string se,
                   std::vector<std::string>& wd) {
    std::unordered_map<std::string, int> um;
    for (int i = 0; i < wd.size(); ++i)
      um.emplace(wd[i], 0);
    // us.insert(se);
    std::queue<std::pair<std::string, int>> q;
    q.push(std::make_pair(sb, 1));
    while (!q.empty()) {
      auto        a = q.front(); q.pop();
      std::string s = a.first;
      int         n = a.second;

      // printf("%d %s\n", n, s.c_str());
      
      if (s == se)
        return n;
      for (int i = 0; i < s.size(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
          if (c == s[i])
            continue;
          std::string ss = s; ss[i] = c;
          if (um.find(ss) == um.end() || um[ss] > 0)
            continue;
          q.push(std::make_pair(ss, n+1));
          um[ss]++;
        }
      }
    }    
    return 0;
  }
};

int main() {
  std::string sb = "hit";
  std::string se = "cog";
  // std::vector<std::string> wd = {"hot", "dot", "dog", "lot", "log"};  
  std::vector<std::string> wd = {"hot", "dot", "dog", "lot", "log", "cog"};  

  Solution s;
  printf("%d\n", s.ladderLength(sb, se, wd));
  
  return 0;
}
