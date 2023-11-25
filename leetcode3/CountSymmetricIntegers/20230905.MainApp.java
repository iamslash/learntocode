// Copyright (C) 2023 by iamslash

import java.util.*;

// 27ms 84.56% 43.7MB 24.73%
// brute force
// O(N) O(1)
class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int num = low; num <= high; ++num) {
            String numStr = Integer.toString(num);
            int n = numStr.length();
            if (n % 2 == 1) {
                continue;
            }            
            int h = n / 2, sum = 0;
            for (int i = 0; i < n; ++i) {
                int digit = numStr.charAt(i) - '0';
                if (i < h) {
                    sum += digit;
                } else {
                    sum -= digit;
                }
            }
            if (sum == 0) {
                cnt++;
            }
        }
        return cnt;
    }
}
