// Copyright (C) 2023 by iamslash

import java.util.*;

// 0 0 0
// 0 1 0
// 0 0 0
//
// ans: 0 4 0 0 0
//
// 1 0 0
// 0 0 0
// 0 0 0
//
// ans: 3 1 0 0 0

// 147ms 79.64% 55.6MB 36.38%
// brute force
// O(HW) O(HW)
class Solution {
    public long[] countBlackBlocks(int h, int w, int[][] coords) {
        Map<Long, Integer> cntMap = new HashMap<>();
        long[] ans = {(h - 1L) * (w - 1), 0, 0, 0, 0};
        for (int [] coord : coords) {
            for (int y = coord[0]; y < coord[0] + 2; ++y) {
                for (int x = coord[1]; x < coord[1] + 2; ++x) {
                    if (y > 0 && y < h && x > 0 && x < w) {
                        long key = x * 100000L + y;
                        ans[cntMap.getOrDefault(key, 0)]--;
                        cntMap.put(key, cntMap.getOrDefault(key, 0) + 1);
                        ans[cntMap.getOrDefault(key, 0)]++;                        
                        // System.out.printf("y: %d, x: %d, ansIdx: %d\n", y, x, cntMap.getOrDefault(key, 0));
                    }
                }
            }
        }
        return ans;
    }
}




