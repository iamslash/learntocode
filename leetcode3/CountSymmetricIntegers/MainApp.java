// Copyright (C) 2023 by iamslash

import java.util.*;

// 26ms 81.74% 43.8MB 5.83%
// brute force
// O(N) O(1)
class Solution {
    public int countSymmetricIntegers(int lo, int hi) {
        int cnt = 0;
        for (int num = lo; num <= hi; ++num) {
            String numStr = String.valueOf(num);
            int n = numStr.length();
            if (n % 2 == 1) {
                continue;
            }
            int half = n / 2, sum = 0;
            for (int i = 0; i < half; ++i) {
                sum += (numStr.charAt(i) - '0');
                sum -= (numStr.charAt(i + half) - '0');
            }
            // System.out.printf("num: %d, sum: %d, n: %d\n", num, sum, n);
            if (sum == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}
