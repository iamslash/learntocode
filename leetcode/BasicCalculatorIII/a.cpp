/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <cctype>
#include <numeric>
#include <vector>


//  s: 1 + 1
//          i
// op: '+'
//  r: 1 1

// recursion
// 8ms 96.64% 10.1MB 59.89%
class Solution {
 public:
  int calculate(std::string s) {
    int i = 0;
    return parseExpr(s, i);
  }
    
  int64_t parseExpr(std::string& s, int& i) {
    std::vector<int64_t> nums;
    char op = '+';
    for (; i < s.length() && op != ')'; i++) {
      // printf("s[%d]: '%c', op: %c\n", i, s[i], op);
      if (s[i] == ' ')
        continue;
      int64_t num = s[i] == '(' ? parseExpr(s, ++i) : parseNum(s, i);
      switch(op) {
        case '+' :
          nums.push_back(num);
          break;
        case '-' :
          nums.push_back(-num);
          break;
        case '*' :
          nums.back() *= num;
          break;
        case '/' :
          nums.back() /= num;
          break;
      }            
      op = s[i];

    }
    return (int)std::accumulate(nums.begin(), nums.end(), 0);
  }
    
  int64_t parseNum(std::string& s, int& i) {
    // printf("  s[%d]: '%c'\n", i, s[i]);    
    int64_t n = 0;
    while(i < s.length() && isdigit(s[i]))
      n = s[i++] - '0' + 10 * n;
    return n;
  }
};

int main() {
  // std::string s = "1 + 1";
  // std::string s = " 6-4 / 2 ";
  // std::string s = "2*(5+5*2)/3+(6/2+8)";
  std::string s = "(2+6* 3+5- (3*14/7+2)*5)+3";

  Solution sln;
  printf("%d\n", sln.calculate(s));
  
  return 0;
}
