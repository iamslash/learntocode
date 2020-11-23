/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>

// back tracking with pruning
//   j
//  i
// 112358
class Solution {
 private:
  bool check(std::string s1, std::string s2, std::string num) {
    // base condition
    if (s1.size() > 1 && s1[0] == '0' ||
        s2.size() > 1 && s2[0] == '0')
      return false;
    std::string sum = add(s1, s2);
    if (num == sum)
      return true;
    if (num.size() <= sum.size() ||
        sum.compare(num.substr(0, sum.size())) != 0)
      return false;
    // recursion
    return check(s2, sum, num.substr(sum.size()));
  }
  std::string add(std::string a, std::string b) {
    std::string rslt;
    int i = a.size() - 1;
    int j = b.size() - 1;
    int c = 0;
    while (i >= 0 || j >= 0) {
      int s = c + (i >= 0 ? (a[i--] - '0') : 0) +
          (j >= 0 ? (b[j--] - '0') : 0);
      rslt.push_back(s % 10 + '0');
      c = s / 10;
    }
    if (c)
      rslt.push_back(c + '0');
    std::reverse(rslt.begin(), rslt.end());    
    return rslt;
  }
  
 public:
  bool isAdditiveNumber(std::string s) {
    if (s.size() < 3)
      return false;
    for (int i = 1; i <= s.size()/2; ++i) {
      for (int j = 1; j <= (s.size()-i)/2; ++j) {
        if (check(s.substr(0, i),
                  s.substr(i, j),
                  s.substr(i+j)))
          return true;
      }
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.isAdditiveNumber("112358"));
  printb(sln.isAdditiveNumber("199100199"));
  printb(sln.isAdditiveNumber("0"));
  
  return 0;
}
