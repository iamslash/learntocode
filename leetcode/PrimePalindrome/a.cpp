/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>

// 68ms 55.85% 8.4MB 38.40%
// O(NlgN) O(1)
class Solution {
 private:
  bool isPrime(int N) {
    if (N < 2 || ((N & 1) == 0))
      return N == 2;
    for (int i = 3; i * i <= N; i += 2) {
      if (N % i == 0)
        return false;
    }
    return true;
  }
 public:
  int primePalindrome(int N) {
    if (8 <= N && N <= 11)
      return 11;
    for (int num = 1; num < 10e5; ++num) {
      std::string s = std::to_string(num);
      if (num != 2 && ((s[0] - '0') & 1) == 0)
        continue;
      std::string r(s.rbegin(), s.rend());
      int pal = std::stoi(s + r.substr(1));
      if (pal >= N && isPrime(pal))
        return pal;
    }
    return -1;
  }
};

int main() {
  Solution sln;
  printf("%d\n", sln.primePalindrome(6));
  printf("%d\n", sln.primePalindrome(8));
  printf("%d\n", sln.primePalindrome(13));
  
  return 0;
}
