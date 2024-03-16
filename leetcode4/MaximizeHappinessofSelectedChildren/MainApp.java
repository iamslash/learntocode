// Copyright (C) 2024 by iamslash

import java.util.*;

// k: 2
// h: 1 2 3

// 36ms 24.31% 61.5MB 64.60%
// sort
// O(NlgN) O(1)
class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int n = happiness.length;
        long ans = 0;
        Arrays.sort(happiness);

        for (int i = n - 1; i >= 0 && k > 0; --i, --k) {
            ans += Math.max(0, happiness[i] - (n - i - 1));
        }

        return ans;
    }
}
