// Copyright (C) 2023 by iamslash

import java.util.*;


//      k: 1
//               i
//   nums: 3 1 4 3 2 2 4
//                     j
// cntMap: 3 1 4 2
//         1 0 1 1
//    ans: 4


// sliding window
// O(N) O(N)
class Solution {
    public long countGood(int[] nums, int k) {
        long ans = 0L;
        Map<Integer, Integer> cntMap = new HashMap<>();
        int n = nums.length;
        for (int i = 0, j = 0; j < n; ++j) {
            k -= cntMap.getOrDefault(nums[j], 0);
            cntMap.put(nums[j], cntMap.getOrDefault(nums[j], 0) + 1);
            while (k <= 0) {
                cntMap.put(nums[i], cntMap.get(nums[i]) - 1);
                k += cntMap.get(nums[i++]);
            }
            ans += i;
        }
        return ans;
    }
}

//      k: 2
//         i
//   nums: 3 1 4 3 2 2 4
//               j
//    cnt: 0
// cntMap: 3 1 4 2
//         1 0 1 1
//    ans: 4


// 66ms 52.30% 53.1MB 87.89%
// sliding window
// O(N) O(N)
class Solution {
    public long countGood(int[] nums, int k) {
        int i = 0, j = 0, n = nums.length;
        Map<Integer, Integer> cntMap = new HashMap<>();
        long cnt = 0, ans = 0;
        while (j < n) {
            // Expand window
            cntMap.put(nums[j], cntMap.getOrDefault(nums[j], 0) + 1);
            cnt += cntMap.get(nums[j]) - 1;
            // Shrink window
            while (i < j && cnt >= k) {
                ans += n - j;
                cntMap.put(nums[i], cntMap.get(nums[i]) - 1);
                cnt -= cntMap.get(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
}
 
