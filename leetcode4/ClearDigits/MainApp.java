// Copyright (C) 2024 by iamslash

import java.util.*;

// s: c b 3 4 3

// 1ms 100.00% 42.6MB 31.03%
// brute force
// O(N) O(1)
class Solution {
    public String clearDigits(String s) {
        StringBuilder sb = new StringBuilder();

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                sb.deleteCharAt(sb.length() - 1);
            } else {
                sb.append(c);
            }
        }
        
        return sb.toString();
    }
}
