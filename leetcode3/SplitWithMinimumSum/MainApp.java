// Copyright (C) 2023 by iamslash

import java.util.*;

// num: 4 3 2 5
//      2 3 4 5
//      2 4
//      3 5

// num: 6 8 7
//      6 7 8
//      6 8
//      7

// 1ms 50.00% 39.6MB 50.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int splitNum(int num) {
        char[] digits = Integer.toString(num).toCharArray();
        int n = digits.length, num1 = 0, num2 = 0;
        Arrays.sort(digits);
        for (int i = 0; i < n; i += 2) {
            num1 = num1 * 10 + (digits[i] - '0');
            if (i + 1 < n) {
                num2 = num2 * 10 + (digits[i + 1] - '0');
            }
        }
        return num1 + num2;
    }
}
