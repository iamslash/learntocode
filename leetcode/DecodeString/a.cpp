/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <stack>

// 0ms 100.00%
class Solution {
 public:
  std::string decodeString(std::string s) {
    std::stack<std::pair<int, std::string>> stck;
    stck.push({0, ""});
    std::string k = "";
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] >= '0' && s[i] <= '9') {
        k += s[i];
      } else if (s[i] == '[') {
        stck.push({std::stoi(k), ""});
        k = "";
      } else if (s[i] == ']') {
        auto pr1 = stck.top(); stck.pop();
        auto& pr2 = stck.top();
        for (int i = 0; i < pr1.first; ++i) {
          pr2.second += pr1.second;
        }        
      } else {
        auto& pr = stck.top();
        pr.second += s[i];
      }
    }

    return stck.top().second;
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.decodeString("3[a]2[bc]").c_str());
  printf("%s\n", sln.decodeString("3[a2[c]]").c_str());
  printf("%s\n", sln.decodeString("2[abc]3[cd]ef").c_str());
  
  return 0;
}
