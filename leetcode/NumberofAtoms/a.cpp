/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <map>
#include <stack>

// 8ms 100.00% 9.5MB 0.00%
// O(N) O(N)
class Solution {
 public:
  std::string countOfAtoms(std::string f) {
    std::stack<std::map<std::string, int>> stck;
    std::map<std::string, int> mp;
    int i = 0;
    while (i < f.size()) {
      if (f[i] == '(') {
        stck.push(std::move(mp));
        mp = std::map<std::string, int>();
        ++i;
      } else if (f[i] == ')') {
        int j = i + 1;
        int k = j;
        while (j < f.size() && std::isdigit(f[j]))
          ++j;
        std::string sss = j == k ? "1" : f.substr(k, j-k);
        int num = std::max(std::stoi(sss), 1);
        for (auto pr : mp)
          stck.top()[pr.first] += pr.second * num;
        mp = std::move(stck.top()); stck.pop();        
        i = j;        
      } else {
        int j = i + 1;
        while (j < f.size() && std::islower(f[j]))
          ++j;
        std::string name = f.substr(i, j-i);
        int k = j;
        while (j < f.size() && std::isdigit(f[j]))
          ++j;
        std::string sss = j == k ? "1" : f.substr(k, j-k);
        // printf("[%s]\n", sss.c_str());          
        int num = std::max(std::stoi(sss), 1);
        mp[name] += num;
        i = j;
      }
    }
    std::string rslt;
    for (auto pr : mp) {
      rslt += pr.first;
      if (pr.second > 1)
        rslt += std::to_string(pr.second);
    }    
    return rslt;
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.countOfAtoms("H2O").c_str());
  printf("%s\n", sln.countOfAtoms("Mg(OH)2").c_str());
  printf("%s\n", sln.countOfAtoms("K4(ON(SO3)2)2").c_str());
  
  return 0;
}
