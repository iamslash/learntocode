// Copyright (C) 2021 by iamslash

import java.util.*;

// dividend: 10
//  divisor: 3

// O(lgN) O(1)
class Solution {
    public int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1 && dividend == Integer.MIN_VALUE) {
            return Integer.MAX_VALUE;
        }
        int ans = 0;
        boolean ansSign = (dividend < 0) ^ (divisor < 0);
        long dividendLong = dividend;
        long divisorLong = divisor;
        dividendLong = dividendLong < 0 ? -dividendLong : dividendLong;
        divisor = divisor < 0 ? -divisor : divisor;
        while (dividendLong >= divisorLong) {
            long delta = divisorLong;
            long quo = 1;
            while (dividendLong >= delta) {
                dividendLong -= delta;
                ans += quo;
                delta <<= 1;
                quo <<= 1;                
            }
        }
        return ansSign ? -ans : ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
