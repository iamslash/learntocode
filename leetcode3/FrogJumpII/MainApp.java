// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: greedy
//
// Find maximum cost among minimum cost. (pretty ambigous)
// Given frogs like this. (f1 means forward, f2 means backward)
// f1 f2 f2 f1
// We will change like this for minimum cost.
// f1 f2 f1 f2
// Then find maximum cost.
//
// Notice: stones[0] is 0

//                 i
// stones: 0 2 5 6 7
//    ans:     5 4 2

// 2ms 99.87% 55.9MB 74.47%
// greedy algorithm
// O(N) O(1)
class Solution {
    public int maxJump(int[] stones) {       
        int n = stones.length, maxCost = stones[1];
        for (int i = 2; i < n; ++i) {
            maxCost = Math.max(maxCost, stones[i] - stones[i-2]);
        }
        return maxCost;
    }
}
