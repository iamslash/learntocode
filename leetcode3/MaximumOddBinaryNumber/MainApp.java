// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 43.5MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public String maximumOddBinaryNumber(String s) {
        int n = s.length(), oneCnt = 0, zeroCnt = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') {
                oneCnt++;
            } else {
                zeroCnt++;
            }
        }
        oneCnt--;
        StringBuilder sb = new StringBuilder();        
        while (oneCnt-- > 0) {
            sb.append('1');
        }
        while (zeroCnt-- > 0) {
            sb.append('0');
        }
        return sb.append('1').toString();
    }
}
