// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 3 4 1 2 3 1
//               i
//       1 1 1 2 3 3 4
//               j
//  ans: [1, 2]
//       [1]
//       [1]

// 2ms 99.79% 43.5MB 44.07%
// hash map
// O(N) O(N)
class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = nums.length, freqs[] = new int[n + 1];
        for (int num : nums) {
            int idx = freqs[num];
            if (idx >= ans.size()) {
                ans.add(new ArrayList<>());
            }
            ans.get(idx).add(num);
        }
        return ans;
    }
}
