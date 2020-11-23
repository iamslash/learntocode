/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 7332
//  i
// 120
//

// i
// 322

// back and forth
// 4ms 100.00% 10MB 76.47%
class Solution {
 public:
  int monotoneIncreasingDigits(int N) {
    std::string s = std::to_string(N);
    if (s.size() <= 1)
      return N;
    // check monotone increasing number
    // then return
    // else decrease first digit and other digits are 9.
    int i = 0;
    for (i = 0; i < s.size() - 1; ++i) {
      if (s[i] > s[i+1])
        break;
    }
    if (i == s.size() - 1)
      return N;
    while (i >= 1 && s[i-1] > s[i]-1)
      --i;
    s[i]--;
    while (++i < s.size())
      s[i] = '9';    
    return std::stoi(s);
  }
};

int main() {

  Solution sln;
  printf("%d\n", sln.monotoneIncreasingDigits(1234));
  printf("%d\n", sln.monotoneIncreasingDigits(322));
  printf("%d\n", sln.monotoneIncreasingDigits(120));
  printf("%d\n", sln.monotoneIncreasingDigits(10));
  
  return 0;
}
