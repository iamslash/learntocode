// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea:
// 0 <= n <= 1_000_000
// Exhaustive search
// int[] digits = new int[]{1, 2, 3, 4, 5, 6}
// digits[a]: remained freq of 'a'

// 1939ms 7.32% 39.3MB 96.34%
// backtracking
class Solution {
    private long ans = Integer.MAX_VALUE;
    private boolean beautiful(int[] digits) {
        for (int i = 1; i <= 6; ++i) {
            if (digits[i] != 0 && digits[i] != i) {
                return false;
            }
        }
        return true;
    }
    private void dfs(int n, int[] digits, long num) {
        // System.out.println(num);
        // base
        if (num > n && beautiful(digits)) {
            ans = Math.min(ans, num);
            return;
        }
        if (num > 100 * n) {
            return;
        }
        // recursion
        for (int i = 1; i <= 6; ++i) {
            if (digits[i] == 0) {
                continue;
            }
            digits[i]--;
            dfs(n, digits, num * 10 + i);
            digits[i]++;
        }
    }
    public int nextBeautifulNumber(int n) {
        int[] digits = new int[]{0, 1, 2, 3, 4, 5, 6};
        dfs(n, digits, 0L);
        return (int)ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
