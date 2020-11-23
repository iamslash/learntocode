#include <cstdio>
#include <vector>
#include <string>

// 4ms 100.00% 9.8MB 100.00%
// O(N) O(N)
class Solution {
 public:
  std::vector<std::string> generatePossibleNextMoves(std::string s) {
    int n = s.size();
    std::vector<std::string> rslt;
    for (int i = 1; i < n; ++i) {
      if (s[i] == '+' && s[i-1] == '+') {
        s[i] = s[i-1] = '-';
        rslt.push_back(s);
        s[i] = s[i-1] = '+';
      }
    }
    return rslt;
  }
};

int main() {
  Solution sln;
  auto rslt = sln.generatePossibleNextMoves("++++");
  for (auto& a : rslt)
    printf("%s\n", a.c_str());
  return 0;
}