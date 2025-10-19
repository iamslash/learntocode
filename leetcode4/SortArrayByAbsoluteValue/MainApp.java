// Copyright (C) 2025 by iamslash

import java.util.*;

// 8ms 53.85% 45.61MB 52.14%
// sort
// O(NlgN) O(N)
class Solution {
    public int[] sortByAbsoluteValue(int[] nums) {
        int n = nums.length;
        Integer[] numArr = new Integer[n];
        for (int i = 0; i < n; ++i) {
            numArr[i] = nums[i];
        }

        Arrays.sort(numArr, (a , b) -> Math.abs(a) - Math.abs(b));

        for (int i = 0; i < n; ++i) {
            nums[i] = numArr[i];
        }

        return nums;
    }
}
