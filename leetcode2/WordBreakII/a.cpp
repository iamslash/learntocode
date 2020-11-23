/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// cat
// Time Limit Exceeded
// 8ms 76.78%
class Solution {
 private:
  std::vector<std::string> m_rslt;
  std::vector<std::string> m_D;
  std::unordered_map<std::string, std::vector<std::string>> m_C;
  std::vector<std::string> solve(int step, std::string s) {

    // for (int i = 0; i < step; ++i)
    //   printf("_");
    // printf("%s\n", s.c_str());
    
    // base
    if (m_C.count(s) > 0)
      return m_C[s];

    std::vector<std::string> rslt;

    if (s.size() == 0) {
      rslt.push_back("");
      return rslt;
    }

    // recursion
    for (const auto& d : m_D) {
      if (s.size() >= d.size() &&
          s.substr(0, d.size()).compare(d) == 0) {
        const auto& subrslt = solve(step+1, s.substr(d.size()));
        for (const auto& suba : subrslt) {
          std::string t = d;
          if (!suba.empty())
            t += " " + suba;
          rslt.push_back(t);
        }
      }
    }
    m_C[s] = rslt;
    return rslt;
  }
 public:
  std::vector<std::string> wordBreak(const std::string& s,
                                     std::vector<std::string>& D) {
    m_D = D;
    return solve(0, s);
  }
};

int main() {
  std::string s = "catsanddog";
  std::vector<std::string> D = {"cat", "cats", "and", "sand", "dog"};
  // std::string s = "pineapplepenapple";
  // std::vector<std::string> D = {"apple", "pen", "applepen", "pine", "pineapple"};
  // std::string s = "catsandog";
  // std::vector<std::string> D = {"cats", "dog", "sand", "and", "cat"};
  Solution sln;
  auto rslt = sln.wordBreak(s, D);
  for (const auto& r : rslt)
    printf("%s\n", r.c_str());
  
  return 0;
}
