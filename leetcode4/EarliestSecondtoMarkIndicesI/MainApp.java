// Copyright (C) 2024 by iamslash

import java.util.*;

// nums: 2 2 0
//      
// idxs: 2 2 2 2 3 2 2 1
//       i

// nums: 1 3
//       
// idxs: 1 1 1 2 1 1 1
//       i

// Idea:
//
// Can perform just one of the operations.

// 1ms 100.00% 44.7MB 86.80%
// binary search
// O(NlgN) O(N)
// difficult to understand
class Solution {
    private boolean isValid(int[] nums, int[] idxs, int idx) {
        int n = nums.length, visitCnt = 0, rst = 0;
        boolean[] visit = new boolean[n];
        for (int i = idx; i >= 0; i--) {
            int pos = idxs[i];
            if (visit[pos]) {
                if (rst > 0) {
                    rst--;
                }
            } else {
                visit[pos] = true;
                visitCnt++;
                rst += nums[pos];
            }
        }
        return rst == 0 && visitCnt == n;
    }

    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        for (int i = 0; i < changeIndices.length; i++) {
            changeIndices[i]--;
        }

        if (!isValid(nums, changeIndices, changeIndices.length - 1)) {
            return -1;
        }

        int lo = 0, hi = changeIndices.length - 1;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2 ;
            if (isValid(nums, changeIndices, mi)) {
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi + 1;
    }
}
