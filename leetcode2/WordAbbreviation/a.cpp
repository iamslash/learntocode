/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>

// 80ms 78.12% 25.8MB 50.00%
// greedy
// O(N^2) O(N)
class Solution {
 private:
  std::string getAbbr(std::string s, int i = 0) {
    //  i  n
    // abcd
    int n = s.size();
    if (n - i < 4)
      return s;
    int cnt = n - i - 2;
    return s.substr(0, i+1) + std::to_string(cnt) + s[n-1];
  }
 public:
  std::vector<std::string> wordsAbbreviation(
      std::vector<std::string>& D) {
    //
    int n = D.size();
    std::vector<std::string> abbrs;
    std::vector<int> abbrbegs(n, 0);
    for (auto& s : D)
      abbrs.push_back(getAbbr(s));
    for (int i = 0; i < n; ++i) {
      while (true) {
        std::unordered_set<int> dups;
        for (int j = i + 1; j < n; ++j) {
          if (abbrs[i] == abbrs[j])
            dups.insert(j);
        }
        if (dups.empty())
          break;
        dups.insert(i);
        for (int k : dups)
          abbrs[k] = getAbbr(D[k], ++abbrbegs[k]);
      }
    }
    return abbrs;
  }
};

int main() {

  std::vector<std::string> D = {"like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"};
  Solution sln;
  auto r = sln.wordsAbbreviation(D);
  for (auto& s : r)
    printf("%s ", s.c_str());
  printf("\n");
  
  return 0;
}
