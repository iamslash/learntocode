// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.30% 42.4MB 27.68%
// linear traversal
// O(N) O(1)
class Solution {
    public boolean isBalanced(String num) {
        int[] sums = new int[2];

        for (int i = 0; i < num.length(); ++i) {
            int digit = num.charAt(i) - '0';

            sums[i % 2] += digit;
        }

        return sums[0] == sums[1];
    }
}
