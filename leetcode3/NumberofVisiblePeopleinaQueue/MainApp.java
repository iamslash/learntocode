// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: mono stack
//
// Create a non-increasing stack
//
//        i
//    H: 10 6 8 5 11 9
//  ans:  0 0 0 0  0 0
// stck:
//
//                   i
//    H: 10 6 8 5 11 9
//  ans:  3 1 2 0  0 0
// stck: 11  

// 143ms 36.41% 62.1MB 48.23%
// mono stack
// O(N) O(N)
class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        int n = heights.length;
        int[] ans = new int[n];
        Stack<Integer> stck = new Stack<>();
        for (int i = 0; i < n; ++i) {
            // Resolve
            while (!stck.isEmpty() &&
                   heights[stck.peek()] < heights[i]) {
                ans[stck.pop()]++;
            }
            // Push
            if (!stck.isEmpty()) {
                ans[stck.peek()]++;
            }
            stck.push(i);
        }
        return ans;
    }
}
