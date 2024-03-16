// Copyright (C) 2021 by iamslash

import java.util.*;

// dividend: 10
//  divisor: 3

// // 1ms 99.96%
// // O(lgN) O(1)
// class Solution {
//     public int divide(int dividend, int divisor) {
//         if (divisor == 1) {
//             return dividend;
//         }
//         if (divisor == -1 && dividend == Integer.MIN_VALUE) {
//             return Integer.MAX_VALUE;
//         }
//         int ans = 0;
//         boolean ansSign = (dividend < 0) ^ (divisor < 0);
//         long dividendLong = dividend;
//         long divisorLong = divisor;
//         dividendLong = dividendLong < 0 ? -dividendLong : dividendLong;
//         divisorLong = divisorLong < 0 ? -divisorLong : divisorLong;
//         while (dividendLong >= divisorLong) {
//             long delta = divisorLong;
//             long quo = 1;
//             while (dividendLong >= delta) {
//                 dividendLong -= delta;
//                 ans += quo;
//                 delta <<= 1;
//                 quo <<= 1;                
//             }
//         }
//         return ansSign ? -ans : ans;
//     }
// }

// 1ms 99.96% 36.4MB 28.83%
// just use Integer
// O(lgN) O(1)
class Solution {
    public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        int a = Math.abs(dividend), b = Math.abs(divisor), ans = 0, x = 0;
        // a >= b occurs TLE
        while (a - b >= 0) {
            x = 0;
            // a >= (b << x << 1) occurs TLE
            // why (a - (b << x) > 0) occurs Wrong Answer
            //   2147483647
            //   2
            while (a - (b << x << 1) >= 0) {
                ++x;
            }
            ans += (1 << x);
            a -= (b << x);
        }
        return (dividend > 0) == (divisor > 0) ? ans : -ans;
    }
}


public class MainApp {
  public static void main(String[] args) {
      System.out.println(Integer.MAX_VALUE == ((1 << 31)-1));
      System.out.println(Integer.MIN_VALUE == (1 << 31));
  }
}
