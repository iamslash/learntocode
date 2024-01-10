// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.75% 44.9MB 5.65%
// brute force
// O(N) O(1)
class Solution {
    public int areaOfMaxDiagonal(int[][] dimensions) {
        double maxDiag = 0;
        int n = dimensions.length, maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int w = dimensions[i][0], h = dimensions[i][1];
            int area = w * h;
            double diag = Math.sqrt(w*w + h*h);
            if (diag >= maxDiag) {
                if (diag == maxDiag) {
                    maxArea = Math.max(maxArea, area);
                } else {
                    maxArea = area;
                }
                maxDiag = diag;
            }
        }
        return maxArea;
    }
}
