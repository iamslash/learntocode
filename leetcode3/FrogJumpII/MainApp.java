// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: greedy
//
// Given frogs like this.
// f1 f2 f2 f1
// We will change like this for minimum path
// f1 f2 f1 f2

//                 i
// stones: 0 2 5 6 7
//    ans:     5 4 2

// 2ms 100.00% 56.3MB 76.94%
// greedy algorithm
// O(N) O(1)
class Solution {
    public int maxJump(int[] stones) {
        int maxPath = stones[1], n = stones.length;
        for (int i = 2; i < n; ++i) {
            maxPath = Math.max(maxPath, stones[i] - stones[i-2]);
        }
        return maxPath;
    }
}
