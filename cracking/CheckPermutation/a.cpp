// Copyright (C) 2016 by iamslash

// Check Permutation: Given two strings, write a method to decide if
// one is a permutation of the other.

// corner case:
// - char is multibyte ?? unicode ??
    
#include <string>
#include <algorithm>

bool IsPermutation(const std::string& _s0, const std::string& _s1) {

  std::string s0(_s0);
  std::string s1(_s1);
  std::sort(s0.begin(), s0.end());
  std::sort(s1.begin(), s1.end());

  for (auto it = s1.begin(); it != s1.end(); ++it) {
    if (s0.find(*it) == std::string::npos)
      return false;
  }
  
  return true;
}   

int main() {
    std::string s0 = "ABCDEFG";
    std::string s1 = "BFG";
    printf("%d : %s, %s\n", IsPermutation(s0, s1), s0.c_str(), s1.c_str());
    printf("%d : %s, %s\n", IsPermutation(s1, s0), s1.c_str(), s0.c_str());

    return 0;
}
