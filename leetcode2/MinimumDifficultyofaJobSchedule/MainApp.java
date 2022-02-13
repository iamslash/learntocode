// Copyright (C) 2022 by iamslash

import java.util.*;

//             D: 2
//                d
//                i
// jobDifficulty: 6 5 4 3 2 1
//                          j
//             C: 1 M M M M M 0

// 10ms 75.80% 41.9MB 16.91%
// iterative dynamic programming
// O(DN^2) O(N)
class Solution {
    public int minDifficulty(int[] jobDifficulty, int days) {
        int n = jobDifficulty.length, MAX_JOB_SCORE_SUM = 300_000;
        if (n < days) {
            return -1;
        }
        // C[i]: min job difficulty starts with i-th job
        int[] C = new int[n+1];
        Arrays.fill(C, MAX_JOB_SCORE_SUM);
        C[n] = 0;

        for (int d = 0; d < days; ++d) {
            for (int i = 0; i < n-d; ++i) {
                int maxScore = 0;
                C[i] = MAX_JOB_SCORE_SUM;
                for (int j = i; j < n-d; ++j) {
                    maxScore = Math.max(maxScore, jobDifficulty[j]);
                    C[i] = Math.min(C[i], maxScore + C[j+1]);
                }
            }
        }        
        return C[0];
    }
}

// 37ms 14.86% 42.6MB 7.53%z
// recursive dynamic programming
// O(DN^2) O(N)
class Solution {
    private final int MAX_SUM = 300_000;
    private int max(int[] A, int beg) {
        int maxVal = 0;
        for (int i = beg; i < A.length; ++i) {
            maxVal = Math.max(maxVal, A[i]);
        }
        return maxVal;
    }
    private int dfs(int[][] C, int[] jobDifficulty, int d, int i) {        
        // base
        int n = jobDifficulty.length;
        if (d <= 0) {
            return MAX_SUM;
        }
        if (d == 1) {
            return max(jobDifficulty, i);
        }
        // memo
        if (C[d][i] >= 0) {
            return C[d][i];
        }
        // recursion
        int r = MAX_SUM;
        int frontMaxDifficulty = 0;
        for (int j = i; j + d - 1 < n; ++j) {
            frontMaxDifficulty = Math.max(frontMaxDifficulty, jobDifficulty[j]);
            r = Math.min(r, frontMaxDifficulty + dfs(C, jobDifficulty, d-1, j+1));
        }
        return C[d][i] = r;
    }
    public int minDifficulty(int[] jobDifficulty, int days) {
        int n = jobDifficulty.length;
        if (n < days) {
            return -1;
        }
        // C[i][j]: min sum of difficulty when i day j job
        int[][] C = new int[days+1][n];
        for (int i = 0; i <= days; ++i) {
            Arrays.fill(C[i], -1);
        }
        int ans = dfs(C, jobDifficulty, days, 0);
        if (ans >= MAX_SUM) {
            return -1;
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
