/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
// 
// dir
//     subdir1
//     subdir2
//         file.ext
// 0ms 100.00%
class Solution {
 public:
  int lengthLongestPath(std::string s) {
    std::vector<int> path;
    int rslt = 0;
    int lv = 0;
    int len = 0;
    bool isfile = false;
    
    for (int i = 0; i < s.size(); ++i) {
      char c = s[i];
      // printf("%c\n", c);
      if (c == '\n') {
        lv = 0;
        len = 0;
        isfile = false;        
      } else if (c == '\t') {
        lv++;        
      } else if (c == '.') {
        isfile = true;
        len++;
      } else {
        len++;
        if (path.size() <= lv)
          path.push_back(len);
        path[lv] = len;
        if (isfile) {
          int last = std::accumulate(path.begin(), path.begin() + lv + 1, 0, std::plus<int>());
          rslt = std::max(rslt, last + lv);
        }
      }
    }
    return rslt;
  }
};
 
int main() {

  Solution sln;
  // printf("%d\n", sln.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"));
  // printf("%d\n", sln.lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
  printf("%d\n", sln.lengthLongestPath("a.tar.gz"));
  
  return 0;
}
