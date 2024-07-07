// Copyright (C) 2024 by iamslash

import java.util.*;

// digits: 2 9 9
//         3 0 0

// 0ms 100.00% 42.1MB 6.49%
// early return
// O(N) O(1)
class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        int[] ans = new int[n + 1];
        ans[0] = 1;
        return ans;
    }
}
