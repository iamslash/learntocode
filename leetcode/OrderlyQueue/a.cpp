/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <algorithm>

// 
// cba

// baaca
// aacab
// aaabc

// 12ms 100.00%
// 11.4MB 0.00%
// O(NlgN) O(1)
class Solution {
 public:
  std::string orderlyQueue(std::string S, int K) {
    if (K > 1) {
      std::sort(S.begin(), S.end());
      return S;
    }
    // rotate
    std::string rslt = S;
    for (int i = 1; i < S.size(); ++i)
      rslt = std::min(rslt, S.substr(i) + S.substr(0, i));
    
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.orderlyQueue("cba", 1).c_str());
  printf("%s\n", sln.orderlyQueue("baaca", 3).c_str());
  
  return 0;
}
