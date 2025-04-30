// Copyright (C) 2025 by iamslash

import java.util.*;

// nums: 2 3 5 10
//       
//
// nums: 2 3 5 7
//  sum: 10
//
// nums: -2 -1 -3 -6 4
//       -6 -3 -2 -1 4
//  sum: -6

// Idea:
//
// total = sumOfElements + outlier + sumNum
// outlier = total - sumNum - sumNum
// outlier might be same with sumNum.
//
// 90ms 52.45% 58.37MB 62.92%
// hash map
// O(N) O(N)
class Solution {
    public int getLargestOutlier(int[] nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int total = 0, maxOutlier = Integer.MIN_VALUE;

        for (int num : nums) {
            total += num;
            cntMap.put(num, cntMap.getOrDefault(num, 0) + 1);
        }

        for (int sumNum : nums) {
            int outlier = total - sumNum - sumNum;
            int bnd = 0;
            if (outlier == sumNum) {
                bnd = 1;
            }
            if (cntMap.getOrDefault(outlier, 0) > bnd) {
                maxOutlier = Math.max(maxOutlier, outlier);
            }
        }

        return maxOutlier;        
    }
}
