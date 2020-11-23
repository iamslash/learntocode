/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

// ab
//  l
// eidbaooo
// i
// j
// 

// 16ms 56.10% 9.8MB 54.44%
// sliding window
// O(N) O(1)
class Solution {
 public:
  bool checkInclusion(std::string a, std::string b) {
    std::unordered_map<char, int> cnts;
    int i = 0, j = 0;
    for(char c : a)
      cnts[c]++;
    int na = a.size();
    int nb = b.size();
    while(j < nb){
      cnts[b[j]]--;
      while (cnts[b[j]] < 0 && i <= j)
        cnts[b[i++]]++;
      if(j - i + 1 == na)
        return true;
      j++;
    }
    return false;
  }
};

// 8ms 98.94% 9.5MB 66.76%
// two vector
// O(N) O(1)
class Solution {
 public:
  bool checkInclusion(std::string a, std::string b) {
    int na = a.size(), nb = b.size();
    if (na > nb)
      return false;
    std::vector<int> C0(26), C1(26);
    for (char c : a)
      ++C0[c-'a'];
    for (int i = 0; i < nb; ++i) {
      ++C1[b[i]-'a'];
      if (i >= na)
        --C1[b[i-na]-'a'];
      if (C0 == C1)
        return true;
    }
    return false;
  }
};

void printb(bool b) {
  printf("%s\n", b ? "true" : "false");
}

int main() {

  Solution sln;
  printb(sln.checkInclusion("ab", "eidbaooo"));
  printb(sln.checkInclusion("ab", "eidboaoo"));  
  
  return 0;
}
