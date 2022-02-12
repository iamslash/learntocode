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

public class MainApp {
  public static void main(String[] args) {
  }
}
