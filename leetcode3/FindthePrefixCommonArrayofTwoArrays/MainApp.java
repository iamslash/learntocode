// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea:
//
// 0. Add 0
// 1. Add 1
// 2. Add 2

// 2ms 100.00% 44MB 20.00%
// brute force
// O(N) O(N)
class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length;
        int[] ans = new int[n], cnts = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            int a = A[i], b = B[i];
            if (i > 0) {
                ans[i] += ans[i-1];
            }
            if (++cnts[a] > 1) {
                ans[i]++;
            }
            if (++cnts[b] > 1) {
                ans[i]++;
            }
        }
        return ans;
    }
}
