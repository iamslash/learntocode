// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: backtracking
//
// There are k buckets. Try all cases.
// dfs(int[] cookies, int k, int cur, int[] children)
//  cookies: input
//        k: input
//      cur: index of current children
// children: cookies of children

// 235ms 75.00% 42.2MB 25.00%
// backtracking
// O(K^N) O(K+N)
class Solution {
    private int maxUnfair = Integer.MAX_VALUE;
    public int distributeCookies(int[] cookies, int k) {
        dfs(cookies, k, 0, new int[k]);
        return maxUnfair;
    }
    private void dfs(int[] cookies, int k, int cur, int[] children) {
        // base
        if (cur == cookies.length) {
            int maxChild = 0;
            for (int child : children) {
                maxChild = Math.max(maxChild, child); 
            }
            maxUnfair = Math.min(maxUnfair, maxChild);
            return;
        }
        // recursion
        for (int i = 0; i < k; ++i) {
            children[i] += cookies[cur];
            dfs(cookies, k, cur+1, children);
            children[i] -= cookies[cur];
        }
    }
}
