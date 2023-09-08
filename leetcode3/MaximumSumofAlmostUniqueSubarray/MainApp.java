// Copyright (C) 2023 by iamslash

import java.util.*;

//    m: 3
//    k: 4
//             i
// nums: 2 6 7 3 1 7
//       

//    m: 3
//    k: 3
//       i
// nums: 1 2 1 2 1 2 1

// 23ms 54.87% 48.1MB 26.80%
// hash map
// O(N) O(N)
class Solution {
    public long maxSum(List<Integer> nums, int m, int k) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int n = nums.size();
        long sum = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            cntMap.put(nums.get(i), cntMap.getOrDefault(nums.get(i), 0) + 1);
            sum += nums.get(i);
            if (i >= k - 1) {
                // Update global max
                if (cntMap.size() >= m) {
                    ans = Math.max(ans, sum);
                }
                // Remove front num
                int frontNum = nums.get(i - k + 1);
                sum -= frontNum;
                cntMap.put(frontNum, cntMap.get(frontNum) - 1);
                if (cntMap.get(frontNum) == 0) {
                    cntMap.remove(frontNum);
                }
            }
        }
        return ans;
    }
}




