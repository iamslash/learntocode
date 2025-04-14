// Copyright (C) 2025 by iamslash

import java.util.*;


//     x   z     y
// . . . . . . . . . .
//

// 0ms 100.00% 40.85MB 86.72%
// math
// O(1) O(1)
class Solution {
    public int findClosest(int x, int y, int z) {
        int distX = Math.abs(z - x);
        int distY = Math.abs(z - y);

        if (distX < distY) {
            return 1;
        }
        if (distX > distY) {
            return 2;
        }
        return 0;
    }
}
