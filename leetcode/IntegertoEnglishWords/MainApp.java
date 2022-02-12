// Copyright (C) 2021 by iamslash

import java.util.*;

// 21ms 19.15% 43.2MB 8.05%
// hash table
// O(N) O(1)
class Solution {
  private final String[] less_20 = new String[]{
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
  private final String[] tens = new String[]{
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
  private final String[] thousands = new String[]{
    "",
    "Thousand",
    "Million",
    "Billion"		
  };
    private String convert(int num) {
      if (num == 0) {
        return "";
      } else if (num < 20) {
        return less_20[num] + " ";
      } else if (num < 100) {
        return tens[num / 10] + " " + convert(num % 10);
      }
      return less_20[num / 100] + " Hundred " + convert(num % 100);
    }          
    public String numberToWords(int num) {
      if (num == 0) {
        return "Zero";
      }
      int i = 0;
      String ans = "";
      while (num > 0) {
        int rem = num % 1000;
        if (rem != 0) {
          ans = convert(rem) + thousands[i] + " " + ans;
        }
        num /= 1000;
        ++i;
      }
      return ans.trim();
    }
}
