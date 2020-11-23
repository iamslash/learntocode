/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// a:2 b:4

// 4ms 100.00% 8.7MB 93.94
// backtracking
class Solution {
 private:
  void dfs(std::string& s, int i,
           std::unordered_map<char, int>& ump,
           std::vector<std::string>& rslt) {
    for (int k = 0; k < i; ++k)
      printf("_");
    printf("%d ", i);
    for (auto pr : ump)
      printf("{%c:%d} ", pr.first, pr.second);
    printf("\n");
    
    // base
    if (i == s.size() / 2) {
      rslt.push_back(s);
      return;
    }

    // recursion
    for (auto& pr : ump) {
      char c = pr.first;
      int cnt= pr.second;
      if (cnt < 2)
        continue;
      s[i] = s[s.size()-1-i] = c;
      ump[c] -= 2;
      dfs(s, i+1, ump, rslt);
      ump[c] += 2;
    }
  }
 public:
  std::vector<std::string> generatePalindromes(std::string s) {
    std::unordered_map<char, int> ump;
    int n = s.size();
    for (char c : s)
      ump[c]++;
    int oddcnt = 0;
    for (auto& pr : ump) {
      if (pr.second % 2) {
        if (++oddcnt > 1)
          return {};
        s[n/2]= pr.first;
      }
    }
    std::vector<std::string> rslt;
    dfs(s, 0, ump, rslt);
    return rslt;
  }
};

int main() {
  Solution sln;
  auto rslt = sln.generatePalindromes("aabbbb");
  for (auto& s : rslt)
    printf("%s\n", s.c_str());
  return 0;
}
