// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: iterative dynamic programming
//
// C[i]: max profit ends with index i.
// C[n] is answer.
// C[e] = max(C[e], C[s] + cost);

// 47ms 92.78% 103.1MB 80.65%
// iterative dynamic programming
// O(NK) O(N)
class Solution {
    public int maximizeTheProfit(int n, List<List<Integer>> offers) {
        int[] C = new int[n + 1];
        List<List<List<Integer>>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<List<Integer>>());
        }
        for (List<Integer> offer : offers) {
            adj.get(offer.get(1)).add(offer);
        }
        for (int end = 1; end <= n; ++end) {
            C[end] = C[end - 1];
            for (List<Integer> next : adj.get(end - 1)) {
                C[end] = Math.max(C[end], C[next.get(0)] + next.get(2));
            }
        }
        return C[n];
    }
}
