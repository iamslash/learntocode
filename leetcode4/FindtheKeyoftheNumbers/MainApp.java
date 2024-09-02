// Copyright (C) 2024 by iamslash

import java.util.*;

// num1: 0 9 8 7
// num2: 0 8 7 9
// num3: 0 7 9 8
//  key: 0 7 7 7     

// 1ms 99.49% 40.7MB 97.14%
// math
// O(1) O(1)
class Solution {
    public int generateKey(int num1, int num2, int num3) {
        int key = 0, multiflier = 1;

        for (int i = 0; i < 4; ++i) {
            int digit1 = num1 % 10;
            int digit2 = num2 % 10;
            int digit3 = num3 % 10;
            
            int minDigit = Math.min(digit1, Math.min(digit2, digit3));
            key += minDigit * multiflier;
            
            // System.out.printf("%d %d %d minDigit: %d, key: %d\n", digit1, digit2, digit3, minDigit, key);            

            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            multiflier *= 10;
        }

        return key;
    }
}
