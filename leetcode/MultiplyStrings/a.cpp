/* Copyright (C) 2018 by iamslash */
// https://leetcode.com/problems/multiply-strings/description/

#include <cstdio>
#include <string>
#include <vector>

// 1 2 3
// 4 5 6
//

class Solution {
 public:
  std::string multiply(std::string a, std::string b) {
    int na = a.size();
    int nb = b.size();
    if (na == 0 || nb == 0)
      return "0";
    std::vector<int> r(na + nb, 0);
    int pa = 0, pb = 0; // position of a, b
    int da = 0, db = 0; // digit of a, b
    int sum = 0, carry = 0; // sum of da and db
    for (auto ia = na-1; ia >= 0; --ia, ++pa) {
      carry = 0;
      da = a[ia] - '0';
      pb = 0;
      for (auto ib = nb-1; ib >= 0; --ib, ++pb) {
        db  = b[ib] - '0';
        sum = da * db + r[pa+pb] + carry;
        carry    = sum / 10;
        r[pa+pb] = sum % 10;
      }
      if (carry > 0)
        r[pa+pb] += carry;
    }
    
    // check "0"
    int i = r.size() - 1;
    while (i >= 0 && r[i] == 0)
      --i;
    if (i < 0)
      return "0";
    
    std::string rr;
    while (i >= 0)
      rr += std::to_string(r[i--]);
    return rr;
  }
};

int main() {
  std::string a = "123";
  std::string b = "456";
  
  Solution s;
  printf("%s\n", s.multiply(a, b).c_str());
  
  return 0;
}
