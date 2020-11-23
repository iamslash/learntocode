/* Copyright (C) 2018 by iamslash */

#include <cstdio>
#include <string>
#include <sstream>

class Solution {
 public:
  std::string complexNumberMultiply(std::string a, std::string b) {
    int ra, ia, rb, ib;
    char buff;
    std::stringstream aa(a), bb(b), rslt;
    aa >> ra >> buff >> ia >> buff;
    bb >> rb >> buff >> ib >> buff;
    rslt << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
    return rslt.str();
  }
};

int main() {
  Solution sln;
  printf("%s\n", sln.complexNumberMultiply("1+1i", "1+1i").c_str());
  printf("%s\n", sln.complexNumberMultiply("1+-1i", "1+-1i").c_str());
  
  return 0;
}
