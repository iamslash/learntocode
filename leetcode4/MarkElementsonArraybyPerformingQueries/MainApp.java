// Copyright (C) 2024 by iamslash

import java.util.*;


// nums: 1 2 2 1 2 3 1
//         i
//  qry: 1,2 3,4 4,2

import java.util.Arrays;

// 127ms 54.02% 73MB 42.24%
// sort
// O(M * NlgN) O(N)
class Solution {
    public long[] unmarkedSumArray(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        long sum = 0;
        long[] ans = new long[m];
        Integer[] idxs = new Integer[n]; // To store indices sorted by value
        boolean[] marked = new boolean[n]; // To mark whether an element is marked

        // Calculate initial sum of nums
        for (int num : nums) {
            sum += num;
        }

        // Fill idxs and sort by nums value
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> nums[i] != nums[j] ? nums[i] - nums[j] : i - j);

        int markedCount = 0; 
        for (int i = 0; i < m; ++i) {
            int pos = queries[i][0], cnt = queries[i][1];
            if (!marked[pos]) {
                marked[pos] = true;
                markedCount++;
                sum -= nums[pos]; 
            }

            for (int j = 0; cnt > 0 && markedCount < n; ++j) {
                if (!marked[idxs[j]]) { 
                    marked[idxs[j]] = true;
                    markedCount++;
                    sum -= nums[idxs[j]]; 
                    cnt--;
                }
            }

            ans[i] = sum;
        }

        return ans;
    }
}
