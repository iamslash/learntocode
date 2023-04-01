// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 3  6  8
//   ps: 1 4 10 18
//       1
//
//         

// 50ms 94.84% 59.4MB 87.64%
// partial sum
// O(N) O(N)
class Solution {
    public List<Long> minOperations(int[] nums, int[] queries) {
        int n = nums.length;
        Arrays.sort(nums);
        List<Long> ans = new ArrayList<>();
        long[] ps = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            ps[i+1] = ps[i] + nums[i];
        }
        for (int query : queries) {
            int i = Arrays.binarySearch(nums, query);
            if (i >= 0) {
                i++;
            } else {
                i = ~i; // -(i + 1)
            }
            long cand = i * (long)query - ps[i];
            cand += ps[n] - ps[i] - (n - i) * (long)query;
            ans.add(cand);
        }
        return ans;
    }
}
