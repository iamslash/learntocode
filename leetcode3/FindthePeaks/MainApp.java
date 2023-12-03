// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 100.00% 44.3MB 100.00%
// brute force
// O(N) O(N)
class Solution {
    public List<Integer> findPeaks(int[] mountain) {
        List<Integer> ans = new ArrayList<>();
        int n = mountain.length, cnt = 0;
        for (int i = 1; i < n-1; ++i) {
            if (mountain[i-1] < mountain[i] &&
                mountain[i] > mountain[i+1]) {
                ans.add(i);
            }
        }
        return ans;
    }
}
