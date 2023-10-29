// Copyright (C) 2023 by iamslash

import java.util.*;

// 8ms 50.00% 43.6MB 50.00%
// brute force
// O(N^2) O(N)
class Solution {
    public int sumCounts(List<Integer> nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; ++i) {
            Set<Integer> numSet = new HashSet<>();
            for (int j = i; j < n; ++j) {
                numSet.add(nums.get(j));
                int cnt = numSet.size();
                sum += cnt * cnt;
            }
        }
        return sum;
    }
}
