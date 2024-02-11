// Copyright (C) 2024 by iamslash

import java.util.*;

// points: 6,2 4,4 2,6

// 14ms 66.28% 44.2MB 86.30%
// brute force
// O(N^3) O(1)
class Solution {
    public int numberOfPairs(int[][] points) {
        int ans = 0, n = points.length;
        // i: Alice, j: Bob
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // Alice should be upper left
                // Bob should be lower right
                if (i == j ||
                    points[i][0] > points[j][0] ||
                    points[i][1] < points[j][1]) {
                    continue;
                }

                // Check people on the area.
                int k = 0;
                for (k = 0; k < n; ++k) {
                    if (k == i || k == j) {
                        continue;
                    }
                    if (points[k][1] <= points[i][1] &&
                        points[k][1] >= points[j][1] &&
                        points[k][0] <= points[j][0] &&
                        points[k][0] >= points[i][0]) {
                        break;
                    }
                }
                if (k == n) {
                    ans++;
                }
            }
        }        
        return ans;
    }
}
