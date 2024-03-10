// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 41.7MB 50.00%
// brute force
// O(N) O(N)
class Solution {
    public boolean isGood(int[] nums) {        
        int n = nums.length, maxNum = 0;
        if (n < 2) {
            return false;
        }
        int[] cnts = new int[n + 1];
        Arrays.fill(cnts, 1);
        cnts[n - 1] = 2;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
            if (num >= n || cnts[num] == 0) {
                return false;
            }
            cnts[num]--;
        }
        if (maxNum != n - 1) {
            return false;
        }
        return true;
    }
}
