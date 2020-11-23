/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

// 4ms 74.13% 8.7MB 8.39%
// O(N) O(N)
class Solution {
 public:
  int minAddToMakeValid(std::string s) {
    int r = 0;
    std::stack<int> stck;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        stck.push(s[i]);
      } else {
        if (stck.size())
          stck.pop();
        else
          ++r;
      }
    }

    return r + stck.size();        
  }
};

int main() {
  return 0;
}
