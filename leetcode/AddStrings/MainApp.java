// Copyright (C) 2021 by iamslash

// c: 0 1
// a: 1 9 2
// b: 9 9

// 3ms 45.96% 39.6MB 17.46%
// reverse
// O(N) O(N)
class Solution {
    public String addStrings(String num1, String num2) {
        int m = num1.length(), n = num2.length(), len = Math.max(m, n);
        int c = 0;
        num1 = new StringBuilder(num1).reverse().toString();
        num2 = new StringBuilder(num2).reverse().toString();
        StringBuilder sumSb  = new StringBuilder();
        for (int i = 0; i < len; ++i) {
            int a = i >= m ? 0 : num1.charAt(i) - '0';
            int b = i >= n ? 0 : num2.charAt(i) - '0';
            int quo = (a + b + c) / 10;
            int rem = (a + b + c) % 10;
            sumSb.append((char)(rem + '0'));
            c = quo;
        }
        if (c > 0) {
            sumSb.append((char)(c + '0'));
        }
        return sumSb.reverse().toString();
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
