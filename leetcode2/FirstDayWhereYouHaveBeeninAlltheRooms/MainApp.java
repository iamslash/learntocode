// Copyright (C) 2022 by iamslash

import java.util.*;

// difficult
// Idea: iterative dynamic programming
//
// C[i]: needed days to jump from room 0 to i
// the anser is C[n-1]
//
// Consider from room i-1 to i
// if nextVisit[i-1] == i-1, need 2 days
// else, need 2 + C[i-1] - C[nextVisit[i-1]] days
//
// C[0] = 0
// C[i] = C[i-1] + 2 + C[i-1] - C[nextVisit[i-1]]
//      = 2 + 2 * C[i-1] - C[nextVisit[i-1]]

// 14ms 83.10% 60MB 76.06%
// iterative dynamic programming
// O(N) O(N)
class Solution {
    public int firstDayBeenInAllRooms(int[] nextVisit) {
        int MOD = 1_000_000_007, n = nextVisit.length;
        long[] C = new long[n];
        for (int i = 1; i < n; ++i) {
            C[i] = (2 + 2 * C[i-1] - C[nextVisit[i-1]] + MOD) % MOD;
        }
        return (int)C[n-1];
    }
}

// 8ms 98.59% 85.1MB 73.24%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int firstDayBeenInAllRooms(int[] nexts) {
        // prev: nextVisit[to-1]
        int MOD = 1_000_000_007, n = nexts.length, prev = 0;
        for (int to = 1; to < n; ++to) {
            int swap = nexts[to-1] + (nexts[to-1] - nexts[prev] + 1) + 1;
            if (swap < 0) {
                swap += MOD;
            } else if (swap >= MOD) {
                swap -= MOD;
            }
            prev = nexts[to];
            nexts[to] = swap;
        }
        return nexts[n-1];
    }
}
