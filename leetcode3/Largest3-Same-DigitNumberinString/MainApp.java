// Copyright (C) 2022 by iamslash

import java.util.*;

// 7ms 66.67% 42.1MB 66.67%
// brute force
// O(N) O(1)
class Solution {
    public String largestGoodInteger(String num) {
        String maxStr = "";
        int maxNum = -1, n = num.length();
        for (int i = 0; i < n - 2; ++i) {
            char a = num.charAt(i), b = num.charAt(i+1), c = num.charAt(i+2);
            if (a == b && b == c) {
                int tmpNum = (a - '0') * 100 + (b - '0') * 10 + c;
                if (maxNum < tmpNum) {
                    maxNum = tmpNum;
                    maxStr = String.format("%c%c%c", a, b, c);
                }
            }
        }
        return maxStr;
    }
}
