// Copyright (C) 2023 by iamslash

import java.util.*;

//                  i
// player1: 4 10  7 9
// player2: 6  5  2 3
//   last1: 1 
//   last2:-3

//                     i
// player1: 6  9 10  4 4
// player2: 8 10  5  1 7
//   last1: 2
//   last2: 1
//  score1: 6 15 25 33 41
//  score2: 8 18 28 30 37

// 2ms 100.00% 42.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int isWinner(int[] player1, int[] player2) {
        int last1 = -3, last2 = -3, n = player1.length;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < n; ++i) {
            int score1 = player1[i], score2 = player2[i];
            if (i - last1 <= 2) {
                score1 *= 2;
            }
            if (i - last2 <= 2) {
                score2 *= 2;
            }
            sum1 += score1;
            sum2 += score2;
            if (player1[i] == 10) {
                last1 = i;
            }
            if (player2[i] == 10) {
                last2 = i;
            }
        }
        if (sum1 > sum2) {
            return 1;
        }
        if (sum1 < sum2) {
            return 2;
        }
        return 0;
    }
}
