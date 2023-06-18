// Copyright (C) 2023 by iamslash

import java.util.*;

//    x: 5
//        
//              i
// nums: 20  1 15
//              j
//
//  ans: 36  3  1

// Idea:
//
// A[i] will be used for the cost of other types.  When we rotate
// i-type for k times, min cost is min(A[i-k], ..., A[i-1], A[i]) for
// i-type.
//
//      i: rotated times
//      j: rotated times
// ans[i]: min cost rotated i times
//      

// brute force
// O(N^2) O(N)
class Solution {
    public long minCost(int[] nums, int x) {
        
    }
}
