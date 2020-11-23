/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

// 36ms 83.91%
// O(NS) O(N)
class Solution {
 private:
  void replaceDot(std::string& s) {
  }
  void removePlus(std::string s) {
    
  }
 public:
  int numUniqueEmails(std::vector<std::string>& emails) {
    std::unordered_set<std::string> ust;
    for (auto& s : emails) {

      int pos = s.find_first_of('@');
      std::string name = s.substr(0, pos);
      std::string doma = s.substr(pos);
      
      name.erase(std::remove(name.begin(), name.end(), '.'), name.end());
      pos = name.find_first_of('+');
      if (pos != std::string::npos)
        name.erase(pos);
      
      ust.insert(name+doma);
    }
    return ust.size();
  }
};

int main() {

  std::vector<std::string> emails = {
    "test.email+alex@leetcode.com",
    "test.e.mail+bob.cathy@leetcode.com",
    "testemail+david@lee.tcode.com"
  };
  Solution sln;
  printf("%d\n", sln.numUniqueEmails(emails));
  
  return 0;
}
