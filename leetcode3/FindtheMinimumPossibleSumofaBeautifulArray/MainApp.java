// Copyright (C) 2023 by iamslash

import java.util.*;

// 16ms 63.76% 53.4MB 76.11%
// hash set
// O(N) O(N)
class Solution {
    public long minimumPossibleSum(int n, int target) {
        Set<Integer> numSet = new HashSet<>();
        long sum = 0;
        int num = 0;
        while (numSet.size() < n) {
            num++;
            if (numSet.contains(target - num)) {
                continue;
            }
            sum += num;
            numSet.add(num);            
        }
        return sum;
    }
}
 
// Idea: math
//
// k is (target / 2).
// We think two parts.
// 0) 1, 2, ..., k
// 1) target, target + 1, ..., target + n - k - 1
// sum of first part:
//   k * (k + 1) / 2
// sum of second part:
//   (target + target + n - k - 1) * (n - k) / 2
//
// if n <= k, return n * (n + 1) / 2
// if n > k, return k * (k + 1) / 2 + (tgt + tgt + n - k - 1) * (n - k) / 2
//            
// 
// 0ms 100.00% 39.8MB 92.27%
// math
// O(1) O(1)
class Solution {
    public long minimumPossibleSum(int n, int target) {
        long k = target / 2, t = target;
        if (n <= k) {
            return (long)n * (n + 1) / 2;
        }
        long firstSum = k * (k + 1) / 2;
        long secondSum = (t + t + n - k - 1) * (n - k) / 2;
        return firstSum + secondSum;
    }
}
