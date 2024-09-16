// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 44.5MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public List<Integer> stableMountains(int[] height, int threshold) {
        List<Integer> ans = new ArrayList<>();
        int n = height.length;

        for (int i = 1; i < n; ++i) {
            if (height[i-1] > threshold) {
                ans.add(i);
            }
        }

        return ans;
    }
}
