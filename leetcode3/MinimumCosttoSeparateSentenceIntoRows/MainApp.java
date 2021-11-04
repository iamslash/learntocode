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

// 0ms 100.00% 39.2MB 50.70%
// recursive dynamic programming
// O(N^2) O(N)
class Solution {
    private int dfs(int[] C, String s, int k, int idx) {
        // base
        int n = s.length();        
        if (idx + k >= n) { 
            return 0;
        }
        // memo
        if (C[idx] >= 0) {
            return C[idx];
        }
        // recursion
        int minCost = Integer.MAX_VALUE;
        for (int i = idx; i <= idx + k; ++i) {
            if (s.charAt(i) == ' ') {
                minCost = Math.min(minCost,
                                   (k - i + idx) * (k - i + idx) +
                                   dfs(C, s, k, i+1));
            }
        }
        return C[idx] = minCost;
    }
    public int minimumCost(String s, int k) {
        int[] C = new int[s.length()+1];
        Arrays.fill(C, -1);
        return dfs(C, s, k, 0);
    }
}

// 46ms 40.84% 39MB 74.65%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int minimumCost(String s, int k) {
        // edge cases
        if (s == null || s.length() == 0 || k <= 0) {
            return 0;
        }
        // 
        String[] sArr = s.split(" ");
        int n = sArr.length, minCost = 0;
        int[] C = new int[n+1];
        for (int i = 1; i <= n; ++ i) {
            int len = sArr[i-1].length();
            C[i] = C[i-1] + (k-len)*(k-len);
            if (i == n) {
                minCost = C[i-1];
            }
            int cur = len;
            for (int j = i-1; j >= 1; j--) {
                cur += sArr[j-1].length() + 1;
                if (k - cur < 0) {
                    break;
                }
                C[i] = Math.min(C[i], C[j-1] + (k-cur)*(k-cur));
                minCost = Math.min(minCost, C[j-1]);
            }
        }
        return minCost;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
