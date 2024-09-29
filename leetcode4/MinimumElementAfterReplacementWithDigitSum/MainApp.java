// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 43MB 100.00%
// math
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
    
    public int minElement(int[] nums) {
        int minNum = Integer.MAX_VALUE;

        for (int num : nums) {
            minNum = Math.min(minNum, digitSum(num));
        }

        return minNum;
    }
}
