// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 5 4 1 2 2
//         i
//       1 2 2 4 5
// 

// 117ms 24.28% 56.6MB 61.54%
// hash map, sort
// O(NlgN) O(N)
class Solution {
    public int maximumLength(int[] nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        for (int num : nums) {
            cntMap.put(num, cntMap.getOrDefault(num, 0) + 1);
        }
        Arrays.sort(nums);        
        int ans = 1, n = nums.length;
        if (cntMap.containsKey(1)) {
            if (cntMap.get(1) % 2 == 0) {
                ans = cntMap.get(1) - 1;
            } else {
                ans = cntMap.get(1);
            }
        }
        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            int num = nums[i];
            while (cntMap.containsKey(num) &&
                   cntMap.get(num) >= 2 &&
                   num != 1) {
                cnt += 2;
                num *= num;
            }
            if (cntMap.containsKey(num)) {
                cnt++;
            } else {
                cnt--;
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
