// Copyright (C) 2023 by iamslash

import java.util.*;

//    k: 2
// nums: 1 5 4 2 3

// 2ms 100.00% 40.9MB 100.00%
// hash set
// O(N) O(N)
class Solution {
    public int minOperations(List<Integer> nums, int k) {
        int n = nums.size();
        Set<Integer> numSet = new HashSet<>();
        for (int i = n - 1; i >= 0; --i) {
            int num = nums.get(i);
            if (num <= k) {
                numSet.add(num);
            }
            if (numSet.size() == k) {
                return n - i;
            }
        }
        return n;
    }
}
