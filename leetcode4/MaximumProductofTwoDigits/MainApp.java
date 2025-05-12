// Copyright (C) 2025 by iamslash

import java.util.*;

// 0ms 100.00% 41.28MB 49.50%
// math
// O(N) O(1)
class Solution {
    public int maxProduct(int n) {
        int firstNum = 0, secondNum = 0;

        while (n > 0) {
            int digit = n % 10;

            if (digit > firstNum) {
                secondNum = firstNum;
                firstNum = digit;                
            } else if (digit > secondNum) {
                secondNum = digit;
            }
            
            n /= 10;
        }

        return firstNum * secondNum;
    }
}
