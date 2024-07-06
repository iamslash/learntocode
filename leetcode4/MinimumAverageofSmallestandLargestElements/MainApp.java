// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 7,8,3,4,15,13,4,1
//       1 3 4 4 7 8 13 15
//             i
// avgs: 8 8 6 5.5

// nums: 1,9,8,3,10,5
//       1 3 5 8 9 10
//           i
// avgs: 5.5

// 2ms 98.54% 43.4MB 82.87%
// sort
// O(NlgN) O(1)
class Solution {
    public double minimumAverage(int[] nums) {
        int n = nums.length, half = n / 2;
        Arrays.sort(nums);
        double minAvg = nums[0] + nums[n - 1];

        for (int i = 0; i < half; ++i) {
            minAvg = Math.min(minAvg, ((double)nums[i] + nums[n - 1 - i]) / 2.0); 
            // System.out.println(minAvg);
        }
        
        return minAvg;
    }
}
