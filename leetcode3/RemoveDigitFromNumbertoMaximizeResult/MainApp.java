// Copyright (C) 2022 by iamslash

import java.util.*;

//  digit: 3
// number: 131
//         132
//         134 
//         135

// Idea:
// The number of digigts after removing one digit is same !!!
// Consider cases
// 
// 0. digit and greater than digit: remove left most digit
//         13434
//         13535
// 1. digit and lesser than digit or equal: remove right most digit
//         13132
//         13131
//         13133

// 3
// 
// 133235

// 1ms 98.21% 41.5MB 92.27%
// back and forth
// O(N) O(1)
class Solution {
    public String removeDigit(String number, char digit) {
        int n = number.length(), j = n - 1;
        for (int i = 0; i < n; ++i) {
            if (number.charAt(i) == digit) {
                if (i < n - 1 && number.charAt(i) < number.charAt(i+1)) {
                    return number.substring(0, i) + number.substring(i + 1);
                }
                j = i;
            }
        }
        return number.substring(0, j) + number.substring(j + 1);
    }
}
