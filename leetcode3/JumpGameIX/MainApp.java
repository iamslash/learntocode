// Copyright (C) 2022 by iamslash

import java.util.*;

// costs: 3 7 6 4 2
//            i
//  nums: 3 2 4 4 1
//                j

// Idea: iterative dynamic programming, mono stack
//
// 

// iterative dynamic programming, mono stack
// O(N) O(N)
class Solution {
    public long minCost(int[] nums, int[] costs) {
        int n = nums.length;
        long INF = Long.MAX_VALUE, jump1 = 0, jump2 = 0;
        // C[i]: min cost to n-1 index from i index
        long[] C = new long[n];
        Stack<Integer> incStck = new Stack<>();
        Stack<Integer> decStck = new Stack<>();
        incStck.push(n-1);
        decStck.push(n-1);
        for (int idx = n-2; idx >= 0; --idx) {
            while (!incStck.isEmpty() && nums[idx] <= nums[incStck.peek()]) {
                incStck.pop();
            }
            while (!decStck.isEmpty() && nums[idx] > nums[decStck.peek()]) {
                decStck.pop();
            }
            int incTop = incStck.peek();
            int decTop = decStck.peek();
            jump1 = incStck.isEmpty() ? INF : costs[incTop] + C[incTop];
            jump2 = decStck.isEmpty() ? INF : costs[decTop] + C[decTop];
            C[idx] = Math.min(jump1, jump2);
            incStck.add(idx);
            decStck.add(idx);
        }
        return C[0];
    }
}
