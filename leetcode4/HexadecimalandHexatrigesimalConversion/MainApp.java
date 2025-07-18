// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 100.00% 41.98MB 92.56%
// math
// O(N) O(1)
class Solution {

    private char getDigitChar(int digit) {
        char c = '0';

        if (digit < 10) {
            c += digit;
        } else {
            c = (char)('A' + digit - 10); 
        }
        
        return c;
    }
    
    public String concatHex36(int n) {
        StringBuilder concatedStr = new StringBuilder();

        // n^3
        int n3 = n * n * n;
        while (n3 > 0) {
            int digit = n3 % 36;
            n3 /= 36;

            concatedStr.append(getDigitChar(digit));
        }

        // n^2
        int n2 = n * n;
        while (n2 > 0) {
            int digit = n2 % 16;
            n2 /= 16;

            concatedStr.append(getDigitChar(digit));
        }

        return concatedStr.reverse().toString();
    }
}
