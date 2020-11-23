/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/simplify-path/description/

#include <cstdio>
#include <string>
#include <vector>

class Solution {
 public:
  std::string simplifyPath(std::string path) {
    std::string r, s;
    std::vector<std::string> v;
    for (int i = 0; i < path.size(); ++i) {
      // printf("%2d %c %s\n", i, path[i], s.c_str());
      if (path[i] == '/') {
         // printf("  %2d %s\n", i, s.c_str());
        if (s.empty() || s == ".") {  // 
          // printf("    empty\n");
        } else if (s == "..") {
          // printf("    double\n");
          if (!v.empty())
            v.pop_back();
        } else {
          // printf("    etc\n");
           v.push_back(s);
        }
        s = "";
      } else {
        s += path[i];
      }
    }
    if (!s.empty()) {
      if (s == "..") {
        if (!v.empty())
          v.pop_back();
      } else if (s != ".") {
        v.push_back(s);
      }
    }
   
    // printf("%d\n", v.size());
    for (int i = 0; i < v.size(); ++i) {
      r += "/" + v[i];
    }
    if (r.empty())
      r = "/";
    return r;
  }
};

int main() {
  
  Solution sln;
  // printf("%s\n", sln.simplifyPath("/home/").c_str());  
  // printf("%s\n", sln.simplifyPath("/a/./b/../../c/").c_str());  
  // printf("%s\n", sln.simplifyPath("/../").c_str());  
  printf("%s\n", sln.simplifyPath("/...").c_str());  
  printf("%s\n", sln.simplifyPath("/..").c_str());  
  printf("%s\n", sln.simplifyPath("/.").c_str());  
  return 0;
}
