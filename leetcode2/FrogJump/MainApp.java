// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: iterative dynamic programming
//
// The forg can only jump in the forward direction.
// stones is sorted in a strictly increasing order.
// stones[0] == 0
// The last jump to reach 0 position is 1.
// second jumps are 0(1 - 1), 1(1 + 0), 2(1 + 1).
// Define stoneLastJumpsMap {pos of stone : last jump set}.

// 40ms 65.32% 46.7MB 85.32%
// iterative dynamic programming, hash map
// O(N^2) O(N)
class Solution {
    public boolean canCross(int[] stones) {
        int n = stones.length;

        Map<Integer, HashSet<Integer>> stoneLastJumpsMap = new HashMap<Integer, HashSet<Integer>>(n);
        for (int i = 0; i < n; ++i) {
            stoneLastJumpsMap.put(stones[i], new HashSet<>());
        }
        stoneLastJumpsMap.get(0).add(1);

        for (int i = 0; i < n - 1; ++i) {
            int stonePos = stones[i];

            for (int jump : stoneLastJumpsMap.get(stonePos)) {
                int reachPos = stonePos + jump;
                if (reachPos == stones[n - 1]) {
                    return true;
                }

                HashSet<Integer> jumpSet = stoneLastJumpsMap.get(reachPos);
                if (jumpSet != null) {
                    if (jump - 1 > 0) {
                        jumpSet.add(jump - 1);
                    }
                    jumpSet.add(jump);
                    jumpSet.add(jump + 1);
                }
            }
        }

        return false;
    }
}
