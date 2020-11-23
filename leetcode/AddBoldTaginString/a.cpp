/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// abcxyz123
// 101--0100-
void printv(std::vector<int> V) {
  for (int a : V)
    printf("%d ", a);
  printf("\n");
}

// 20ms 99.69% 10.8MB 100.00%
class Solution {
 public:
  std::string addBoldTag(std::string s, std::vector<std::string>& D) {
    int n = s.size();
    std::vector<int> V(n+1, 0);
    for (auto& a : D) {
      int i = -1;
      while ((i = s.find(a, i+1))>=0) {
        V[i]++;
        V[i+a.size()]--;
      }
    }
    // printv(V);
    std::string rslt;
    int prv = 0;
    for (int i = 0; i <= n; ++i) {
      int cur = prv + V[i];
      if (cur > 0 && prv == 0)
        rslt += "<b>";
      if (cur == 0 && prv > 0)
        rslt += "</b>";
      if (i == n)
        break;
      rslt.push_back(s[i]);
      prv = cur;
    }

    return rslt;
  }
};

int main() {

  // std::string s = "abcxyz123";
  // std::vector<std::string> D = {
  //   "abc", "123"};
  std::string s = "aaabbcc";
  std::vector<std::string> D = {
    "aaa","aab","bc"};

  Solution sln;
  printf("%s\n", sln.addBoldTag(s, D).c_str());
  
  return 0;
}
