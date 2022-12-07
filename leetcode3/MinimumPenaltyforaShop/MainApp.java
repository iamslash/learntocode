// Copyright (C) 2022 by iamslash

import java.util.*;

// customers:   Y Y N Y
//    psOpen:   0 0 1 1
//   psClose: 0 1 2 2 3
//   penalty:   3 2 2        

// 31ms 23.41% 53.2MB 43.88%
// prefix sum
// O(N) O(N)
class Solution {
    public int bestClosingTime(String s) {
        int n = s.length(), psOpen = 0;
        int[] psClose = new int[n+1];
        for (int i = 0; i < n; ++i) {
            psClose[i+1] = psClose[i] + (s.charAt(i) == 'Y' ? 1 : 0);
        }
        int minPenalty = psClose[n], minIdx = 0;
        for (int i = 0; i < n; ++i) {
            int penalty = psOpen + psClose[n] - psClose[i];
            if (penalty < minPenalty) {
                minPenalty = penalty;
                minIdx = i;
            }
            if (s.charAt(i) == 'N') {
                psOpen++;
            }
        }
        if (psOpen < minPenalty) {
            return n;
        }
        return minIdx;
    }
}
