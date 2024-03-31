// Copyright (C) 2024 by iamslash

import java.util.*;

//    k: 11
// nums: 1

// Idea:
//
// We need two kinds of counts.
// 0. The count of increasing one by one from `1` to `num`.
// 1. The count of num to make the sum of `nums` great equal than k. 

// 7ms 14.99% 40.8MB 37.71%
// brute force
// O(K) O(1)
class Solution {
    public int minOperations(int k) {
        int minOps = k;

        for (int num = 1; num <= k; ++num) {
            int ops = (int)Math.ceil(k / (double)num);
            minOps = Math.min(minOps, num + ops - 2);
        }

        return minOps;
    }
}

// math
// O(sqrtN) O(sqrtN)
class Solution {
    public int minOperations(int k) {
        int a = (int) Math.sqrt(k);
        return a + (k - 1) / a - 1;
    }
}

// 0ms 100.00% 40.6MB 48.54%
// math
// O(sqrtN) O(sqrtN)
class Solution {
    public int minOperations(int k) {
        return (int)Math.ceil(Math.sqrt(4 * k)) - 2;
    }
}
