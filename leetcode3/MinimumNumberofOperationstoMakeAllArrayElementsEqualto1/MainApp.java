// Copyright (C) 2023 by iamslash

import java.util.*;

// i
// 6 10 15
//       j
//

//     i
// 2 4 3 5
//       j

// Idea: gcd
// If there is one at least, the ans is "n - oneCnt".
// If there is no one,
//   Find gcd one between pairs.
//   If you find it, replace other numbers with 1 (n - 1).
//   The ans is "count for finding gcd one + (n - 1)".

// 1ms 99.85% 42.2MB 51.20%
// gcd
// O(N^2) O(1)
class Solution {
    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    public int minOperations(int[] nums) {
        int oneCnt = 0, n = nums.length;
        for (int num : nums) {
            oneCnt += (num == 1) ? 1 : 0;
        }
        if (oneCnt > 0) {
            return n - oneCnt;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = Math.min(ans, j - i + (n - 1));
                    break;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
