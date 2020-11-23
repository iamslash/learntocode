/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

// 396ms 31.38% 19.1MB 47.70%
// two pointers
// O(N) O(1)
class Solution {
 public:
  string entityParser(string s) {
    unordered_map<string, string> dict;
    dict["&quot;"] = "\"";
    dict["&apos;"] = "'";
    dict["&amp;"] = "&";
    dict["&gt;"] = ">";
    dict["&lt;"] = "<";
    dict["&frasl;"] = "/";
    string ans;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '&') {
        string special;
        int j = i;
        for (j = i; j < s.size() && s[j] != ';'; ++j)
          special += s[j];
        if (j < s.size())
          special += ';';
        // printf("i: %d, j: %d, special: %s\n", i, j, special.c_str());
        if (dict.find(special) != dict.end()) {
          ans += dict[special];
        } else {
          ans += special;
        }
        i = j;
      } else {
        ans += s[i];
      }
    }
    return ans;    
  }
};
