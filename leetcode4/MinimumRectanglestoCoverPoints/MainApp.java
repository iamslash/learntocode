// Copyright (C) 2024 by iamslash

import java.util.*;

//                             i
//  pts: 1,0 1,4 1,8 2,1 3,5 4,6
// last:   2               4
//  cnt:   1               2

//                             i
//  pts: 0,0 1,4 1,8 2,1 3,5 4,6
// last:   2               4
//  cnt:   1               2

// 5ms 76.51% 96.9MB 78.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int minRectanglesToCoverPoints(int[][] points, int w) {
        Arrays.sort(points, (a, b) -> a[0] - b[0]);
        int n = points.length, last = -1, cnt = 0;

        for (int[] pt : points) {
            int x = pt[0], y = pt[1];
            if (x > last) {
                last = x + w;
                cnt++;
            }
        }
        
        return cnt;
    }
}
