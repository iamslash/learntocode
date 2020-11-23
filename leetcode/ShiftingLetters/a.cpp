/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <numeric>

// 56ms 77.92% 11.5MB 80.20%
// O(N) O(1)
class Solution {
 public:
  std::string shiftingLetters(std::string S, std::vector<int>& shifts) {
    int n = shifts.size();
    for (int i = n - 2; i >= 0; --i)
      shifts[i] += shifts[i+1] % 26;
    for (int i = 0; i < n; ++i) {
      // printf("s[i]: %c, S[i]: %d\n", S[i], shifts[i]);
      S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
    }
    // printf("\n");
    return S;
  }
};

int main() {
  std::string S = "abc";
  std::vector<int> shifts = {3, 5, 9};

  Solution sln;
  printf("%s\n", sln.shiftingLetters(S, shifts).c_str());
  
  return 0;
}
