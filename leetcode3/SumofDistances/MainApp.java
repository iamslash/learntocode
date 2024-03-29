// Copyright (C) 2023 by iamslash

import java.util.*;

// nums: 1 3 1 1 2

// Time Limit Exceeded
// hash map
// O(N) O(N)
class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        Map<Integer, List<Integer>> valIdxsMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            valIdxsMap.putIfAbsent(nums[i], new ArrayList<>());
            valIdxsMap.get(nums[i]).add(i);
        }
        for (int i = 0; i < n; ++i) {
            long sum = 0;
            for (int j : valIdxsMap.get(nums[i])) {
                if (i != j) {
                    sum += Math.abs(i - j);
                }
            }
            ans[i] = sum;
        }
        return ans;
    }
}

// Idea: prefix sum, back and forth
//
//    idx: x y z p q
//   nums: 1 1 1 1 1
//
// Let's think about ans[z].
//
// ans[2]: |z - x| + |z - y| + |z - p| + |z - q|
//
//         |z - x| + |z - y| = 2 * z - (x + y)
//                           = cnt * curIdx - prevIdxSum
//                             
//         |z - p| + |z - q| = 2 * z - (p + q)
//                           = cnt * curIdx - prevIdxSum
// cnts[num] is for count of num
// idxSums[num] is for previous index sum of num
//
// See also:
//   https://leetcode.com/problems/intervals-between-identical-elements/
//     0 <= nums[i] <= 10^5 

// 95ms 19.49% 83.4MB 21.56%
// prefix sum, back and forth
// O(N) O(N)
class Solution {
    private void sum(int[] nums, long[] ans, int beg, int inc) {
        int n = ans.length;
        Map<Long, Long> cntMap = new HashMap<>();
        Map<Long, Long> sumMap = new HashMap<>();
        for (int i = beg, j = 0; i >= 0 && i < n; i += inc, ++j) {
            long num = (long)nums[i];
            ans[i] += cntMap.getOrDefault(num, 0L) * j - sumMap.getOrDefault(num, 0L);
            cntMap.put(num, cntMap.getOrDefault(num, 0L) + 1);
            sumMap.put(num, sumMap.getOrDefault(num, 0L) + j);
            // System.out.printf("i: %d, num: %d\n", i, num);
            // System.out.println(sumMap);
        }
    }
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        sum(nums, ans, 0, 1);
        sum(nums, ans, n - 1, -1);
        return ans;
    }
}
