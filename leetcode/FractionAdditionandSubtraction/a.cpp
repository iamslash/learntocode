/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <sstream>

// A/B + a/b = (Ab + aB) / (Bb)
// O(N) O(1)
class Solution {
 private:
  int gcd(int a, int b) {
    if (b == 0)
      return a;
    return gcd(b, a%b);
  }
 public:
  std::string fractionAddition(std::string s) {
    std::istringstream iss(s);
    int A = 0, B = 1, a, b;
    char _;
    while (iss >> a >> _ >> b) {
      A = A * b + a * B;
      B = B * b;
      int g = std::abs(gcd(A, B));
      A /= g;
      B /= g;      
    }
    return std::to_string(A) + '/' + std::to_string(B);
  }
};

int main() {

  Solution sln;
  printf("%s\n", sln.fractionAddition("-1/2+1/2").c_str());
  printf("%s\n", sln.fractionAddition("-1/2+1/2+1/3").c_str());
  printf("%s\n", sln.fractionAddition("1/3-1/2").c_str());
  printf("%s\n", sln.fractionAddition("5/3+1/3").c_str());
  
  return 0;
}
