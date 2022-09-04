// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 100.00% 42.7MB 56.25%
// brute force
// O(N) O(1)
class Solution {
    public boolean checkDistances(String s, int[] distances) {
        int[] prevIdxs = new int[26];
        Arrays.fill(prevIdxs, -1);
        for (int i = 0; i < s.length(); ++i) {
            int idx = s.charAt(i) - 'a';
            if (prevIdxs[idx] >= 0) {
                int dist = i - prevIdxs[idx] - 1;
                if (distances[idx] != dist) {
                    return false;
                }
            }
            prevIdxs[idx] = i;
        }
        return true;
    }
}
