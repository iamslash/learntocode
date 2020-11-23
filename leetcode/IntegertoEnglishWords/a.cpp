/* Copyright (C) 2019 by iamslash */

#include <cstdio>
#include <string>
#include <vector>

// 0ms 100.00%
// O(1) O(1)
const std::vector<std::string> g_less_then_20 = {
  "",
  "One",
  "Two",
  "Three",
  "Four",
  "Five",
  "Six",
  "Seven",
  "Eight",
  "Nine",
  "Ten",
  "Eleven",
  "Twelve",
  "Thirteen",
  "Fourteen",
  "Fifteen",
  "Sixteen",
  "Seventeen",
  "Eighteen",
  "Nineteen"
};
const std::vector<std::string> g_tens = {
  "",
  "Ten",
  "Twenty",
  "Thirty",
  "Forty",
  "Fifty",
  "Sixty",
  "Seventy",
  "Eighty",
  "Ninety"
};
const std::vector<std::string> g_thousands = {
  "",
  "Thousand",
  "Million",
  "Billion"
};

class Solution {
 private:
  std::string _numberToWords(int num) {
    if (num == 0)
      return "";
    else if (num < 20)
      return g_less_then_20[num] + " ";
    else if (num < 100)
      return g_tens[num / 10] + " " + _numberToWords(num%10);
    return g_less_then_20[num / 100] + " Hundred " + _numberToWords(num % 100);  
  }
  
 public:
  std::string numberToWords(int num) {
    if (num == 0)
      return "Zero";
    int i = 0;
    std::string s = "";
    while (num > 0) {
      int rem = num % 1000;
      if (rem != 0)
        s = _numberToWords(rem) + g_thousands[i] + " " + s;
      num /= 1000;
      ++i;
    }

    while (s.back() == ' ')
      s.pop_back();

    return s;
  }
};

int main() {
  Solution sln;
  printf("\"%s\"\n", sln.numberToWords(123).c_str());
  printf("\"%s\"\n", sln.numberToWords(12345).c_str());
  printf("\"%s\"\n", sln.numberToWords(1234567).c_str());
  return 0;
}
