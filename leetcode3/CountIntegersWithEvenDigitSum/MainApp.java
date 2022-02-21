// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 75.00% 41.3MB 25.00%
// brute force
class Solution {
    private boolean evenDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum % 2 == 0;
    }
    public int countEven(int bnd) {
        int cnt = 0;
        for (int num = 1; num <= bnd; ++num) {
            if (evenDigitSum(num)) {
                cnt++;
            }
        }
        return cnt;
    }
}

// 0ms 100.00% 39.3MB 75.00%
// math
// O(1) O(1)
class Solution {
    public int countEven(int num) {
        int tmp = num, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum % 2 == 0) {
            return tmp / 2;
        }
        return (tmp - 1) / 2;

    }
}
