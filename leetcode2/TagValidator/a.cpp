/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <stack>
#include <string>

using namespace std;

// 4ms 63.04% 6.4MB 86.96%
// stack
// O(N) O(N)
class Solution {
 public:
  bool isValid(string s) {
    stack<string> stck;
    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && stck.empty())
        return false;
      if (s.substr(i, 9) == "<![CDATA[") {
        int j = i + 9;
        i = s.find("]]>", j);
        if (i < 0)
          return false;
        i += 2;
      } else if (s.substr(i, 2) == "</") {
        int j = i + 2;
        i = s.find('>', j);
        string ss = s.substr(j, i - j);
        if (stck.empty() || ss != stck.top())
          return false;
        stck.pop();
      } else if (s.substr(i, 1) == "<") {
        int j = i + 1;
        i = s.find('>', j);
        if (i < 0 || i == j || i - j > 9)
          return false;
        for (int k = j; k < i; ++k) {
          if (!isupper(s[k]))
            return false;
        }
        string ss = s.substr(j, i - j);
        stck.push(ss);
      }
    }
    return stck.empty();
  }
};
