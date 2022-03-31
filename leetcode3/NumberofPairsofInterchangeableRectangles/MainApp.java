// Copyright (C) 2022 by iamslash

import java.util.*;

// 6C2

// 94ms 48.25% 147.8MB 70.43%
// hash map
// O(N) O(N)
class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        long cnt = 0;
        Double ratio = 0.0;
        Map<Double, Integer> freqMap = new HashMap<>();
        for (int[] rec : rectangles) {
            ratio = Double.valueOf(rec[0]) / Double.valueOf(rec[1]);
            cnt += freqMap.getOrDefault(ratio, 0);
            freqMap.put(ratio, freqMap.getOrDefault(ratio, 0) + 1);
        }              
        return cnt;
    }
}

// 22ms 100.00% 99.7MB 85.99%
// hash map, two pointers
// O(N) O(N)
class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        int n = rectangles.length;
        double[] ratios = new double[n];
        for (int i = 0; i < n; ++i) {
            ratios[i] = (double)rectangles[i][0] / rectangles[i][1];
        }
        Arrays.sort(ratios);
        int j = 0;
        long cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (ratios[i-1] == ratios[i]) {
                cnt += i - j;
            } else {
                j = i;
            }
        }
        return cnt;
    }
}
