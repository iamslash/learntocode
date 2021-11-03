// Copyright (C) 2021 by iamslash

import java.util.*;

//      i
// s: i love leetcode
//          k

// 1ms 88.73% 37.7MB 90.14%
// DFS
// O(?) O(?)
class Solution {
    private int dfs(String s, int k, int idx) {
        // base
        int n = s.length();        
        if (idx + k >= n) { 
            return 0;
        }
        // recursion
        int minCost = Integer.MAX_VALUE;
        for (int i = idx; i <= idx + k; ++i) {
            if (s.charAt(i) == ' ') {
                minCost = Math.min(minCost,
                                   (k - i + idx) * (k - i + idx) +
                                   dfs(s, k, i+1));
            }
        }
        return minCost;
    }
    public int minimumCost(String s, int k) {
        return dfs(s, k, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
