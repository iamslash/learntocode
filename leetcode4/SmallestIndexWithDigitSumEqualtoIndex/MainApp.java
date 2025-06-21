// Copyright (C) 2025 by iamslash

import java.util.*;

// 1ms 99.97% 44.62MB 22.69%
// liear tarversal
// O(N) O(1)
class Solution {
    
    private int sumDigits(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;        
    }
    
    public int smallestIndex(int[] nums) {
        int n = nums.length, sum = 0;
        
        for (int i = 0; i < n; ++i) {

            if (i == sumDigits(nums[i])) {
                return i;
            }
        }

        return -1;
    }
}
