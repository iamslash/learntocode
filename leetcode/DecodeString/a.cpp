/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <stack>
#include <map>

using namespace std;

//                     i
//    s: 3 [ a 2 [ c ] ]
//  num: 
// stck: {0, accaccacc}

// 0ms 100.00% 6.9MB 50.07%
// stack
// O(N) O(N)
class Solution {
 public:
  string decodeString(string s) {
    stack<pair<int, string>> stck;
    stck.push({0, ""});
    string num;
    for (char c : s) {
      if (c >= '0' && c <= '9') {
        num += c;
      } else if (c == '[') {
        stck.push({stoi(num), ""});
        num = "";
      } else if (c == ']') {
        auto pr = stck.top(); stck.pop();
        for (int i = 0; i < pr.first; ++i) {
          stck.top().second += pr.second;
        }
      } else {
        stck.top().second += c;
      }
    }
    return stck.top().second;
  }
};
