// Copyright (C) 2025 by iamslash

import java.util.*;

//        i
// s: a b a c c b
// d: 1 3 0 5
// p: 0 1 - - - -

// 1ms 89.71% 44.09MB 40.19%
// hash map
// O(N) O(1)
class Solution {
    public boolean checkDistances(String s, int[] distances) {
        int n = s.length();
        int[] positions = new int[26];
        Arrays.fill(positions, -1);

        for (int pos = 0; pos < n; ++pos) {
            int idx = s.charAt(pos) - 'a';

            if (positions[idx] >= 0) {
                int dist = pos - positions[idx] - 1;
                if (distances[idx] != dist) {
                    return false;
                }
            }

            positions[idx] = pos;
        }

        return true;
    }
}
