// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 -10 7 13 6 8
//       1   0 2  3 1 3
// cnts: 0 1 2 3 4
//       1 2 1 2 0
//                 i

//  val: 5
// nums: 3 0 3 2 4 2 1 1 0 4
//       3 0 3 2 4 2 1 1 0 4
// freq: 0 1 2 3 4
//       2 2 2 2 2

// 7ms 89.30% 58.9MB 75.96%
// hash map
// O(N) O(V)
class Solution {
    public int findSmallestInteger(int[] nums, int val) {
        int[] freqs = new int[val];
        for (int num : nums) {
            freqs[(num % val + val) % val]++;
        }        
        int idx = 0;
        for (int i = 0; i < val; ++i) {
            // System.out.printf("%d ", freqs[i]);
            if (freqs[i] < freqs[idx]) {
                idx = i;
            }
        }
        return val * freqs[idx] + idx;
    }
}
