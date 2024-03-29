// Copyright (C) 2022 by iamslash

import java.util.*;

// 152ms 59.61% 121.5MB 71.84%
// hash set
// O(NlgN) O(N)
class Solution {
    private int reverse(int num) {
        int rst = 0;
        while (num > 0) {
            rst = (rst * 10) + (num % 10);
            num /= 10;
        }
        return rst;
    }
    public int countDistinctIntegers(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
            numSet.add(reverse(num));
        }
        // System.out.println(numSet);
        return numSet.size();
    }
}
