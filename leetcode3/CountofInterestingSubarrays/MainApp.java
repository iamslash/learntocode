// Copyright (C) 2023 by iamslash

import java.util.*;

// modulo: 2
//      k: 1
//           i
//   nums: 1 0 0
// cntMap: 0 1
//         1 1

// modulo: 3
//      k: 0
//         i
//   nums: 3 1 9 6
//               i
//   nums: 1 0 1 1
//    cnt: 1 1 2 0
// cntMap: 0 1 2
//         2 1 1
//    ans: 2

// 31ms 65.40% 62.3MB 32.07%
// hash map
// O(N) O(N)
class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int mod, int k) {
        long ans = 0;
        int cnt = 0; // [0..k)
        Map<Integer, Integer> cntMap = new HashMap<>(Map.of(0, 1));
        for (int num : nums) {
            if (num % mod == k) {
                cnt = (cnt + 1) % mod;
            }
            ans += cntMap.getOrDefault((cnt - k + mod) % mod, 0);
            cntMap.put(cnt, cntMap.getOrDefault(cnt, 0) + 1);
        }
        return ans;
    }
}
