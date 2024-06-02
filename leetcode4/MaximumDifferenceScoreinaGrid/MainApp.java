// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: iterative dynamic programming
//
// Move from c1 to ck with path c1, c2, .., ck,
// score = (c2 - c1) + (c3 - c2) + .... = ck - c1

// 29ms 34.83% 62.4MB 44.75%
// iterative dynamic programming
// O(HW) O(1)
class Solution {
    public int maxScore(List<List<Integer>> grid) {
        final int MAX_VAL = 1_000_000;
        int maxS = -MAX_VAL, h = grid.size(), w = grid.get(0).size();

        for (int y = 0; y < h; ++y) {
            for (int x = 0; x < w; ++x) {
                int preTopMin = y > 0 ? grid.get(y - 1).get(x) : MAX_VAL;
                int preLftMin = x > 0 ? grid.get(y).get(x - 1) : MAX_VAL;
                int preMin = Math.min(preTopMin, preLftMin);

                maxS = Math.max(maxS, grid.get(y).get(x) - preMin);

                if (preMin < grid.get(y).get(x)) {
                    grid.get(y).set(x, preMin);
                }
            }
        }

        return maxS;
    }
}
