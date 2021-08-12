// Copyright (C) 2021 by iamslash

//         i 
//  s: 1 0 1
// n1: 1 0 1
// n2: 0 1 0
// m1: 0 0 1
// m2: 0 1 0

// 1ms 92.53% 37.3MB 69.50%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int numDecodings(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        int n1 = 1, n2 = 0;
        for (int i = 1; i < s.length(); ++i) {
            int m1 = 0, m2 = 0;
            char c = s.charAt(i);
            // count for digit 1
            if (c >= '1' && c <= '9') {
                m1 = n1 + n2;
            }
            // count for digit 2
            int num = Integer.parseInt(s.substring(i-1, i+1));
            if (num >= 10 && num <= 26) {
                m2 = n1;
            }
            n1 = m1;
            n2 = m2;
        }
        return n1 + n2;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
