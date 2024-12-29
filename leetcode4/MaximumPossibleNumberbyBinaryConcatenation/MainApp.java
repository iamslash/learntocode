// Copyright (C) 2024 by iamslash

import java.util.*;

//    10
//  1000
// 10000
// 101 0001 0000

// 5ms 76.29% 42.30% 77.59%
// sort
// O(1) O(1)
class Solution {
    public int maxGoodNumber(int[] nums) {
        String[] strs = new String[3];
        for (int i = 0; i < nums.length; ++i) {
            strs[i] = Integer.toBinaryString(nums[i]);
        }

        Arrays.sort(strs, (a, b) -> (b + a).compareTo(a + b));

        StringBuilder sb = new StringBuilder();
        for (String s : strs) {
            sb.append(s);
        }

        return Integer.parseInt(sb.toString(), 2);
    }
}
