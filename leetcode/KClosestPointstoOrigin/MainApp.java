// Copyright (C) 2024 by iamslash

import java.util.*;

// 28ms 64.48% 49MB 89.27%
// sort
// O(NlgN) O(N)
class Solution {

    private int dist(int[] pt) {
        return pt[0] * pt[0] + pt[1] * pt[1];
    }
    
    public int[][] kClosest(int[][] points, int k) {
        Integer[] idxs = new Integer[points.length]; // Use Integer instead of int
        for (int i = 0; i < points.length; ++i) {
            idxs[i] = i;
        }

        // Now, Arrays.sort can accept a custom Comparator for Integer[]
        Arrays.sort(idxs, (i, j) -> dist(points[i]) - dist(points[j]));

        int[][] ans = new int[k][];
        for (int i = 0; i < k; ++i) {
            ans[i] = points[idxs[i]];
        }
        
        return ans;
    }
}
