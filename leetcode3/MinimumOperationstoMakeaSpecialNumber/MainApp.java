// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// These are numbers can be divided by 25.
// *00
// *25
// *50
// *75

//            i
// num: 2908305

// 1ms 99.87% 40.8MB 99.12%
// math
// O(N) O(1)
class Solution {
    public int minimumOperations(String num) {
        int n = num.length();
        boolean fiveFound = false, zeroFound = false;
        for (int i = n - 1; i >= 0; --i) {
            if (zeroFound && num.charAt(i) == '0') {
                return n - 2 - i;
            }
            if (zeroFound && num.charAt(i) == '5') {
                return n - 2 - i;
            }
            if (fiveFound && num.charAt(i) == '2') {
                return n - 2 - i;
            }
            if (fiveFound && num.charAt(i) == '7') {
                return n - 2 - i;
            }
            if (num.charAt(i) == '5') {
                fiveFound = true;
            }
            if (num.charAt(i) == '0') {
                zeroFound = true;
            }               
        }
        if (zeroFound) {
            return n - 1;
        }
        return n;
    }
}
