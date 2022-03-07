// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 42.2MB 100.00%
// hash map
// O(N) O(1)
class Solution {
    public int mostFrequent(int[] nums, int key) {
        int[] cnts = new int[10001];
        int maxNum = -1, maxCnt = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (i < n-1 && nums[i] == key) {
                int follow = nums[i+1];
                cnts[follow]++;
                if (maxCnt < cnts[follow]) {
                    maxNum = follow;
                    maxCnt = cnts[follow];
                }
            }
        }
        return maxNum;
    }
}
