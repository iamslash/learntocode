#include <cstdio>
#include <string>
#include <vector>

// word

// backtracking
// O(??) O(N)
class Solution {
 private:
  void solve(std::string& s, std::string abbr, int i, 
      std::vector<std::string>& rslt, bool bprvnum) {
//printf("%s %d\n", abbr.c_str(), i);
    // base
    if (i == s.size()) {
      rslt.push_back(abbr);
      return;
    }
    // recursion
    solve(s, abbr+s[i], i+1, rslt, false);
    if (!bprvnum) {
      for (int len = 1; i + len <= s.size(); ++len)
        solve(s, abbr + std::to_string(len), i + len, rslt, true);
    }
  }
 public:
  std::vector<std::string> generateAbbreviations(std::string s) {
    std::vector<std::string> rslt;
    solve(s, "", 0, rslt, false);
    return rslt;
  }
};

int main() {
  Solution sln;
  auto r = sln.generateAbbreviations("word");
  for (auto& s : r)
    printf("%s\n", s.c_str());
  printf("\n");

  return 0;
}