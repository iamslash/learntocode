// Copyright (C) 2021 by iamslash

import java.util.*;

// students: 1 1 0
//           1 0 1
//           0 0 1
//  mentors: 1 0 0
//           0 0 1
//           1 1 0
//
//           1 1 0    1 1 0    3
//           1 0 1    1 0 0    2
//           0 0 1    0 0 1    3
//

// sort
//           0 0 1    0 0 1
//           1 0 1    1 0 0
//           1 1 0    1 1 0

// // 52ms 38.18% 39.3MB 18.24%
// // back tracking
// // O(N!)
// class Solution {
//     int maxScore;
//     private void dfs(boolean[] visit, int[][] students, int[][] mentors,
//                      int i, int scoreSum) {
//         int n = students.length;
//         // base
//         if (i >= n) {
//             maxScore = Math.max(maxScore, scoreSum);
//             return;
//         }
//         // recursion
//         for (int j = 0; j < n; ++j) {
//             if (!visit[j]) {
//                 visit[j] = true;
//                 dfs(visit, students, mentors, i+1,
//                     scoreSum + score(students[i], mentors[j]));
//                 visit[j] = false;
//             }
//         }
//     }
//     private int score(int[] a, int[] b) {
//         int res = 0;
//         for (int i = 0; i < a.length; ++i) {
//             if (a[i] == b[i]) {
//                 res++;
//             }
//         }
//         return res;
//     }
//     public int maxCompatibilitySum(int[][] students, int[][] mentors) {
//         boolean[] visit = new boolean[students.length];
//         dfs(visit, students, mentors, 0, 0);
//         return maxScore;
//     }
// }

// 2ms 92.61% 39.1MB 21.60%
// recursive dynamic programming
// M: length of students
// N: length of answers
// O((M*2^M)*N) O(M*(2^M))
class Solution {
    private int dfs(int[][] C, int[][] students, int[][] mentors,
                    int idx, int bm) {
        int n = students.length;
        // base 
        if (idx == n) {
            return 0;
        }
        // memo
        if (C[idx][bm] != 0) {
            return C[idx][bm];
        }
        // recursion
        int maxScore = 0;
        for (int j = 0; j < mentors.length; ++j) {
            int move = 1 << j;
            if ((bm & move) != 0) {
                continue;
            }
            maxScore = Math.max(maxScore, score(students[idx], mentors[j]) +
                                dfs(C, students, mentors, idx + 1, bm | move));
        }
        return C[idx][bm] = maxScore;
    }
    private int score(int[] a, int[] b) {
        int res = 0;
        for (int i = 0; i < a.length; ++i) {
            if (a[i] == b[i]) {
                res++;
            }
        }
        return res;
    }
    public int maxCompatibilitySum(int[][] students, int[][] mentors) {
        int C[][] = new int[students.length][(1 << mentors.length) - 1];
        return dfs(C, students, mentors, 0, 0);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
