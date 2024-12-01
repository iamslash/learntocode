// Copyright (C) 2024 by iamslash

import java.util.*;

// n: 15
// t: 3
//
//    15
//    16

// 1ms 60.48% 40.9MB 58.50%
// brute force
// O(N) O(1)
class Solution {

    private int productDigits(int n) {
        int prod = 1;
        
        while (n > 0) {
            int digit = n % 10;            
            n /= 10;
            prod *= digit;
        }

        return prod;
    }
    
    public int smallestNumber(int n, int t) {
        while (n <= 100) {

            int prod = productDigits(n);
            if (prod % t == 0) {
                return n;
            }
            
            n++;
        }

        return 0;
    }
}
