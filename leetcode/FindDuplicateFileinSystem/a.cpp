/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

// 60ms 92.86%
//
class Solution {
 public:
  std::vector<std::vector<std::string>> findDuplicate(
      std::vector<std::string>& V) {
    std::unordered_map<std::string, std::vector<std::string>> cont2paths;
    for (auto& s : V) {
      s.push_back(' ');

      int mode = 0; // 0, 1, 2, 3
      std::string path;
      std::string fname;
      std::string content;
      
      // read path, file, content
      for (int i = 0; i < s.size(); ++i) {
        if (mode == 0) {
          if (s[i] != ' ')
            path += s[i];
          else
            mode = 1;
        } else if (mode == 1) {
          if (s[i] != '(')
            fname += s[i];
          else
            mode = 2;
        } else if (mode == 2) {
          if (s[i] != ')')
            content += s[i];
          else
            mode = 3;            
        } else if (mode == 3) {
          //
          std::string fullpath = path + '/' + fname;
          cont2paths[content].push_back(fullpath);

          fname.clear();
          content.clear();
          mode = 1;
        }
      }
      mode = 0;
      path.clear();
    }
    
    std::vector<std::vector<std::string>> rslt;
    for (const auto& pr : cont2paths) {
      if (pr.second.size() > 1) {
        std::vector<std::string> paths;
        for (const std::string& s : pr.second)
          paths.push_back(s);        
        rslt.push_back(paths);
      }
    }
    
    return rslt;
  }
};

int main() {
  std::vector<std::string> V = {
    "root/a 1.txt(abcd) 2.txt(efgh)",
    "root/c 3.txt(abcd)",
    "root/c/d 4.txt(efgh)",
    "root 4.txt(efgh)"
  };
  Solution sln;
  auto rslt = sln.findDuplicate(V);
  for (const auto& l : rslt) {
    for (const auto& a : l) {
      printf("%s ", a.c_str());
    }
    printf("\n");
  }
  
  return 0;
}
