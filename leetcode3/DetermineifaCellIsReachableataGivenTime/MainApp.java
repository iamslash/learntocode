// Copyright (C) 2023 by iamslash

import java.util.*;

// sx,sy: 2,4
// fx,fy: 7,6
//     t: 6

// sx,sy: 1,1
// fx,fy: 1,3
//     t: 2

// * . *
//

// Idea: math
//
// The answer is max(diffx, diffy).
// when max(diffx, diffy) == 0, t should not be 1.

// 1ms 96.65% 39.8MB 48.59%
// math
// O(1) O(1)
class Solution {
    public boolean isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffX = Math.abs(sx - fx), diffY = Math.abs(sy - fy);
        int maxDist = Math.max(diffX, diffY);
        if (maxDist == 0) {
            return t != 1;
        }
        return maxDist <= t;
    }
}
