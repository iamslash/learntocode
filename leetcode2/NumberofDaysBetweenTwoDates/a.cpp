/* Copyright (C) 2020 by iamslash */

#include <cstdio>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

// 0ms 100.00% 5.9MB 89.55%
class Solution {
 private:
  int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int leap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
  }
  int daysOfYear(string a) {
    int y = stoi(a.substr(0, 4));
    int m = stoi(a.substr(5, 2));
    int d = stoi(a.substr(8));
    for (int i = 1971; i < y; ++i) {
      d += leap(i) ? 366 : 365;     
    }
    return d + (m > 2 && leap(y)) + accumulate(begin(days), begin(days) + m - 1, 0);
  }
 public:
  int daysBetweenDates(string a, string b) {
    return abs(daysOfYear(a) - daysOfYear(b));
  }
};
