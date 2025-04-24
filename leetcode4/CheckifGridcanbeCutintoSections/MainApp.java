// Copyright (C) 2025 by iamslash

import java.util.*;


//
//
// n: 5
// rectangles: 1,0,5,2
//             0,2,2,4
//             3,2,5,3
//             0,4,4,5
//
// xs: 1,5 0,2 3,5 0,4
// ys: 0,2 2,4 2,3 4,5
//
//       i
// xs: 0,2 0,4 1,5 3,5
//                 i
// ys: 0,2 2,3 2,4 4,5

// 95ms 63.98% 122.49MB 41.88%
// sort
// O(NlgN) O(N)
class Solution {

    private boolean valid(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);

        int sections = 0;
        int last = intervals[0][1];

        for (int[] interval : intervals) {
            int beg = interval[0], end = interval[1];

            if (last <= beg) {
                if (++sections >= 2) {
                    return true;
                }
            }
            last = Math.max(last, end);
        }

        return false;
    }
    
    public boolean checkValidCuts(int n, int[][] rectangles) {
        int m = rectangles.length;

        int[][] xs = new int[m][2];
        int[][] ys = new int[m][2];

        for (int i = 0; i < m; ++i) {
            xs[i][0] = rectangles[i][0];
            ys[i][0] = rectangles[i][1];
            xs[i][1] = rectangles[i][2];
            ys[i][1] = rectangles[i][3];
        }

        return valid(xs) || valid (ys);
    }
}
