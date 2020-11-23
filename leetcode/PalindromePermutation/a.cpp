#include <cstdio>
#include <string>
#include <unordered_map>

// 4ms 100.00% 8.4MB 28.77%
// O(N) O(1)
class Solution {
 public:
  bool canPermutePalindrome(std::string s) {
    int n = s.size();
    std::unordered_map<char, int> ump;
    for (char c : s)
      ump[c]++;
    int oddcnt = (n%2 == 0) ? 1 : 0;
    for (auto& pr : ump) {
      if (pr.second % 2 != 0)
        oddcnt++;
      if (oddcnt > 1)
          return false;
    }
    return true;         
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.canPermutePalindrome("code") ? "true" : "false");
  printf("%s\n", sln.canPermutePalindrome("aab") ? "true" : "false");
  printf("%s\n", sln.canPermutePalindrome("carerac") ? "true" : "false");
  return 0;
}