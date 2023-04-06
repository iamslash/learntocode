// Copyright (C) 2023 by iamslash

import java.util.*;

// 13ms 98.88% 51MB 80.35%
// sort
// O(NlgN) O(N)
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length, sum = 0;
        int[] diffs = new int[n];
        for (int i = 0; i < n; ++i) {
            diffs[i] = reward1[i] - reward2[i];
            sum += reward2[i];
        }
        Arrays.sort(diffs);
        for (int i = 0; i < k; ++i) {
            sum += diffs[n - 1 - i];
        }
        return sum;
    }
}
