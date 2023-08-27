// Copyright (C) 2023 by iamslash

import java.util.*;


//                 i
//   nums: 1 5 4 3 6
//   stck: 6  
//         4  
//  lefts: - - 1 2 -
// rights: 1 4 4 4 5
//    ans: 1 4 2 1 5

// Idea: mono stack
//
// stck is a non-increasing stack.
// lefts[i] is an index of left great element of i.
// rights[i] is an index of right great element of i.
// ans[i] is rights[i] - lefts[i] - 1; 

// 82ms 60.00% 63.6MB 8.00%
// mono stack
// O(N) O(N)
class Solution {
    public int[] maximumLengthOfRanges(int[] nums) {
        int n = nums.length;
        Stack<Integer> stck = new Stack<>();
        int[] lefts = new int[n], rights = new int[n];
        Arrays.fill(lefts, -1);
        Arrays.fill(rights, n);
        for (int i = 0; i < n; ++i) {
            // Fill rights
            while (!stck.empty() && nums[stck.peek()] < nums[i]) {
                int top = stck.pop();
                rights[top] = i;
            }
            // Fill lefts
            if (!stck.empty() && nums[stck.peek()] > nums[i]) {
                lefts[i] = stck.peek(); 
            }
            // Insert
            stck.push(i);
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = rights[i] - lefts[i] - 1;
        }
        return ans;
    }
}
