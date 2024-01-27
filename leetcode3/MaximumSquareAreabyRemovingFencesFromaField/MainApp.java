// Copyright (C) 2024 by iamslash

import java.util.*;

// 464ms 67.21% 59.8MB 84.11%
// brute force, hash map
// O(N^2) O(N)
class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        long maxSqLen = 0, mod = 1_000_000_007L;
        Set<Integer> hrzSet = new HashSet<>();
        int[] hrzFens = Arrays.copyOf(hFences, hFences.length + 2);
        int[] vrtFens = Arrays.copyOf(vFences, vFences.length + 2);
        hrzFens[hFences.length] = 1;
        hrzFens[hFences.length + 1] = m;
        vrtFens[vFences.length] = 1;
        vrtFens[vFences.length + 1] = n;

        for (int i = 0; i < hrzFens.length; ++i) {
            for (int j = i + 1; j < hrzFens.length; ++j) {
                if (i != j) {
                    hrzSet.add(Math.abs(hrzFens[i] - hrzFens[j]));
                }
            }
        }

        for (int i = 0; i < vrtFens.length; ++i) {
            for (int j = i + 1; j < vrtFens.length; ++j) {
                int diff = Math.abs(vrtFens[i] - vrtFens[j]);
                if (hrzSet.contains(diff)) {
                    maxSqLen = Math.max(maxSqLen, diff);
                }
            }
        }

        if (maxSqLen == 0) {
            return -1;
        }
        return (int)((maxSqLen * maxSqLen) % mod);
    }
}
