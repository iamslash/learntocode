// Copyright (C) 2024 by iamslash

import java.util.*;


// a: 80
// b: 120
//    80 81 82 83 88 

// 4ms 100.00% 44.3MB 100.00%
// math
// O(N) O(1)
class Solution {
    private boolean uniqueDigits(int num) {
        boolean[] digits = new boolean[10];
        while (num > 0) {
            int dgt = num % 10;
            if (digits[dgt] == true) {
                return false;
            }
            digits[dgt] = true;            
            num /= 10;            
        }
        return true;
    }
    public int numberCount(int a, int b) {
        int cnt = 0;
        for (int num = a; num <= b; ++num) {
            if (uniqueDigits(num)) {
                cnt++;
            }
        }
        return cnt;
    }
}
