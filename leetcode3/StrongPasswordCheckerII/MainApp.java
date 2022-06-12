// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 88.37% 42.4MB 18.60%
// brute force
// O(N) O(1)
class Solution {
    public boolean strongPasswordCheckerII(String password) {
        if (password.length() < 8) {
            return false;
        }
        int lowercaseCnt = 0, uppercaseCnt = 0, digitCnt = 0, specCnt = 0;
        for (int i = 0; i < password.length(); ++i) {
            char c = password.charAt(i);
            if (c >= 'a' && c <= 'z') {
                lowercaseCnt++;
            } else if (c >= 'A' && c <= 'Z') {
                uppercaseCnt++;
            } else if (c >= '0' && c <= '9') {
                digitCnt++;
            } else {
                specCnt++;
            }
            if (i > 0 && password.charAt(i-1) == c) {
                return false;
            }
        }
        // System.out.printf("%d %d %d %d\n", lowercaseCnt, uppercaseCnt, digitCnt, specCnt);
        if (lowercaseCnt == 0 ||
            uppercaseCnt == 0 ||
            digitCnt == 0 ||
            specCnt == 0) {
            return false;
        }
        return true;
    }
}
