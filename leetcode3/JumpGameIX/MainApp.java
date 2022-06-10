// Copyright (C) 2022 by iamslash

import java.util.*;

// costs: 3 7 6 4 2
//            i
//  nums: 3 2 4 4 1
//                j

// Idea: iterative dynamic programming, mono stack
//
// 

// 204ms 30.00% 61.5MB 100.00%
// iterative dynamic programming, mono stack
// O(N) O(N)
class Solution {
    public long minCost(int[] nums, int[] costs) {
        int n = nums.length;
        long INF = Long.MAX_VALUE, jump1 = 0, jump2 = 0;
        // C[i]: min cost to n-1 index from i index
        long[] C = new long[n];
        Stack<Integer> ltIdxStck = new Stack<>();
        Stack<Integer> gteIdxStck = new Stack<>();
        ltIdxStck.push(n-1);
        gteIdxStck.push(n-1);
        for (int idx = n-2; idx >= 0; --idx) {
            while (!ltIdxStck.isEmpty() && nums[idx] <= nums[ltIdxStck.peek()]) {
                ltIdxStck.pop();
            }
            while (!gteIdxStck.isEmpty() && nums[idx] > nums[gteIdxStck.peek()]) {
                gteIdxStck.pop();
            }
            jump1 = ltIdxStck.isEmpty() ? INF : costs[ltIdxStck.peek()] + C[ltIdxStck.peek()];
            jump2 = gteIdxStck.isEmpty() ? INF : costs[gteIdxStck.peek()] + C[gteIdxStck.peek()];
            C[idx] = Math.min(jump1, jump2);
            ltIdxStck.add(idx);
            gteIdxStck.add(idx);
        }
        return C[0];
    }
}
