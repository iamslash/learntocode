// Copyright (C) 2024 by iamslash

import java.util.*;

// apples: 1 3 2
//   caps: 1 2 3 4 5
//                 i

// 1ms 100.00% 42.3MB 50.00%
// sort
// O(NlgN) O(1)
class Solution {
    public int minimumBoxes(int[] apples, int[] caps) {
        int sum = 0, m = caps.length;
        for (int num : apples) {
            sum += num;
        }

        Arrays.sort(caps);

        int minCnt = 0;
        for (int i = m - 1; sum > 0 && i >= 0; --i) {
            minCnt++;
            sum -= caps[i];
        }

        return minCnt;
    }
}
