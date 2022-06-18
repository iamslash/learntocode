// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
//
// alice starts with mod3==1: 1 1 2 1 2 ...
// alice starts with mod3==2: 2 2 1 2 1 ...

// 5ms 100.00% 52.4MB 100.00%
// math
// O(N) O(1)
// difficult
class Solution {
    public boolean stoneGameIX(int[] stones) {
        int[] cnts = new int[3];
        for (int a: stones) {
            cnts[a % 3]++;
        }
        if (cnts[0] % 2 == 0) {
            return cnts[1] > 0 && cnts[2] > 0;
        }
        return Math.abs(cnts[1] - cnts[2]) > 2;
    }
}
