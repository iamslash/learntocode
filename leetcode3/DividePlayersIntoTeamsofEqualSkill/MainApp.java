// Copyright (C) 2022 by iamslash

import java.util.*;

// 15ms 100.00% 50MB 87.50%
// sort
// O(NlgN) O(1)
class Solution {
    public long dividePlayers(int[] skills) {
        int n = skills.length, half = n / 2;
        long ans = 0L;
        Arrays.sort(skills);
        int skillSum = skills[0] + skills[n-1];
        for (int i = 0; i < half; ++i) {
            // System.out.printf("sum: %d, skillSum: %d\n", skills[i] + skills[n - 1 -i], skillSum);
            if (skills[i] + skills[n - 1 - i] != skillSum) {
                return -1;
            }
            ans += skills[i] * skills[n - 1 - i];
        }
        return ans;
    }
}
