// Copyright (C) 2023 by iamslash

import java.util.*;

// 3ms 80.00% 42.4MB 90.00%
// brute force
// O(N) O(1)
class Solution {
    private int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    public int differenceOfSum(int[] nums) {
        int sumNum = 0, sumDgt = 0;
        for (int num : nums) {
            sumNum += num;
            sumDgt += digitSum(num);
        }
        return Math.abs(sumNum - sumDgt);
    }
}

// 2ms 100.00% 42.2MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int differenceOfSum(int[] nums) {
        int sumNum = 0, sumDgt = 0;
        for (int num : nums) {
            sumNum += num;
            while (num > 0) {
                sumDgt += (num % 10);
                num /= 10;
            }
        }
        return sumNum - sumDgt;
    }
}
