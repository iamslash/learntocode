// Copyright (C) 2022 by iamslash

import java.util.*;

// 15ms 89.19% 67.8MB 52.25%
// brute force
// O(N) O(N)
class Solution {
    public String maximumNumber(String numStr, int[] change) {
        char[] numArr = numStr.toCharArray();
        int n = numStr.length();
        for (int i = 0; i < n; ++i) {
            if (numArr[i] - '0' < change[numArr[i] - '0']) {
                while (i < n && numArr[i] - '0' <= change[numArr[i] - '0']) {
                    // System.out.printf("i: %d, numArr[i]: %d, change[]: %d\n", i, numArr[i]-'0', change[numArr[i]-'0']);
                    numArr[i] = (char)(change[numArr[i] - '0'] + '0');
                    i++;
                }
                return String.valueOf(numArr);
            }
        }
        return numStr;
    }
}
