// Copyright (C) 2025 by iamslash

import java.util.*;

// 6ms 89.66% 44.27MB 91.112%
// brute force
// O(N^2) O(N)
class Solution {
    public boolean hasSameDigits(String s) {
        int n = s.length();
        StringBuilder srcSb = new StringBuilder(s);

        while (srcSb.length() > 2) {

            StringBuilder dstSb = new StringBuilder();
            for (int i = 0; i < srcSb.length() - 1; ++i) {
                int a = srcSb.charAt(i) - '0';
                int b = srcSb.charAt(i + 1) - '0';
                dstSb.append((char)((a + b) % 10 + '0'));
            }

            srcSb = dstSb;
        }

        return srcSb.charAt(0) == srcSb.charAt(1);
    }
}
