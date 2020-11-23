/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>

using namespace std;

// 0ms 100.00% 6.1MB 100.00%
// brute force
// O(1) O(1)
class Solution {
 private:
  string month(string s) {
    if(s=="Jan")        return "01";
    else if(s=="Feb")   return "02";
    else if(s=="Mar")   return "03";
    else if(s=="Apr")   return "04";
    else if(s=="May")   return "05";
    else if(s=="Jun")   return "06";
    else if(s=="Jul")   return "07";
    else if(s=="Aug")   return "08";
    else if(s=="Sep")   return "09";
    else if(s=="Oct")   return "10";
    else if(s=="Nov")   return "11";
    return "12";
  }
 public:
  string reformatDate(string s) {
    string y, m, d;
    if (s.size() == 12) {
      y = s.substr(8,4);
      m = month(s.substr(4,3));
      d = '0'+s.substr(0,1);
    } else {
      y = s.substr(9,4);
      m = month(s.substr(5,3));
      d = s.substr(0,2);
    }
    return y + '-' + m + '-' + d;
  }
};
