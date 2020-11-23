/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>

// 8ms 96.35% 9.8MB 87.50%
// backtracking
// O(??) o(N)
class Solution {
 private:
  std::unordered_map<std::string, std::vector<char>> m_ump;
  bool dfs(std::string bottom, int start, std::string next) {
    // base
    if (bottom.size() == 1)
      return true;
    // recursion
    if (start == bottom.size() - 1)
      return dfs(next, 0, "");
    for (char c : m_ump[bottom.substr(start, 2)]) {
      if (dfs(bottom, start+1, next+c))
        return true;
    }
    return false;
  }
 public:
  bool pyramidTransition(std::string bottom,
                         std::vector<std::string>& A) {
    for (auto& a : A) {
      m_ump[a.substr(0, 2)].push_back(a[2]);
    }
    return dfs(bottom, 0, "");
  }
};

int main() {
  // std::vector<std::string> A = {"XYD", "YZE", "DEA", "FFF"};
  // std::string bottom = "XYZ";
  std::vector<std::string> A = {"XXX", "XXY", "XYX", "XYY", "YXZ"};
  std::string bottom = "XXYX";
  Solution sln;
  printf("%s\n", sln.pyramidTransition(bottom, A) ? "true" : "false");

  return 0;
}
