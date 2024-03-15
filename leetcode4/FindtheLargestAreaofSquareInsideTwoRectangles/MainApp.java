// Copyright (C) 2024 by iamslash

import java.util.*;

// 206ms 5.22% 45MB 65.70%
// brute force
// O(N^2) O(1)
class Solution {
    private long getArea(int bl1[], int tr1[], int bl2[], int tr2[]) {
        long left = Math.max((long)bl1[0], (long)bl2[0]);
        long right = Math.min((long)tr1[0], (long)tr2[0]);
        long bottom = Math.max((long)bl1[1], (long)bl2[1]);
        long top = Math.min((long)tr1[1], (long)tr2[1]);

        if (left <= right && bottom <= top) {
            long len = Math.min(right - left, top - bottom);
            return len * len;
        }

        return 0;
    }
    
    public long largestSquareArea(int[][] bls, int[][] trs) {
        int n = bls.length;
        long maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                maxArea = Math.max(maxArea,
                                   getArea(bls[i], trs[i], bls[j], trs[j]));
            }
        }

        return maxArea;
    }
}
