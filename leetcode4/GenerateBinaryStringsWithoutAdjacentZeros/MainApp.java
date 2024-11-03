// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.00% 46.3MB 7.30%
// backtracking
// O(2^N) O(N)
class Solution {

    private void dfs(int n, List<String> ans, StringBuilder cand, int last) {

        // base
        if (cand.length() == n) {
            ans.add(cand.toString());
            return;
        }
        
        // recursion
        cand.append('1');
        dfs(n, ans, cand, 1);
        cand.deleteCharAt(cand.length() - 1);

        if (last != 0) {
            cand.append('0');
            dfs(n, ans, cand, 0);
            cand.deleteCharAt(cand.length() - 1);
        }
    }
    
    public List<String> validStrings(int n) {
        List<String> ans = new ArrayList<>();
        dfs(n, ans, new StringBuilder(), -1);
        return ans;
    }
}
