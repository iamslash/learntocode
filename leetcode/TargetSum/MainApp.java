// Copyright (C) 2024 by iamslash

import java.util.*;

//  tgt: 3       
// nums: 1 1 1 1 1
//       i
//
// dfs(0)

// // 591ms 28.51% 41.3MB 69.97%
// // dfs
// // O(2^N) O(lgN)
// class Solution {
//     private int dfs(int[] nums, int tgt, int pos) {
//         // base
//         int n = nums.length;
//         if (pos == n) {
//             if (tgt == 0) {
//                 return 1;
//             }
//             return 0;
//         } 
        
//         // recursion
//         int num = nums[pos], cnt = 0;
//         cnt += dfs(nums, tgt + num, pos + 1);
//         cnt += dfs(nums, tgt - num, pos + 1);

//         return cnt;
//     }
    
//     public int findTargetSumWays(int[] nums, int target) {
//         return dfs(nums, target, 0);
//     }
// }

// // 103ms 45.78% 45.8MB 5.20%
// // recursive dynamic programming
// // O(2^N) O(lgN)
// class Solution {
//     private int dfs(Map<String, Integer> C, int[] nums, int tgt, int pos) {
//         // base
//         int n = nums.length;
//         if (pos == n) {
//             if (tgt == 0) {
//                 return 1;
//             }
//             return 0;
//         }

//         // memo
//         String key = pos + "," + tgt;
//         if (C.containsKey(key)) {
//             return C.get(key);
//         }
        
//         // recursion
//         int num = nums[pos], cnt = 0;
//         cnt += dfs(C, nums, tgt + num, pos + 1);
//         cnt += dfs(C, nums, tgt - num, pos + 1);

//         C.put(key, cnt);

//         return cnt;
//     }
    
//     public int findTargetSumWays(int[] nums, int target) {
//         Map<String, Integer> C = new HashMap<>();
//         return dfs(C, nums, target, 0);
//     }
// }

// 73ms 51.18% 45.5MB 10.97%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        Map<Integer, Integer> cache1 = new HashMap<>();
        cache1.put(0, 1);

        for (int num : nums) {
            Map<Integer, Integer> cache2 = new HashMap<>();
            for (int sum : cache1.keySet()) {
                int key1 = sum + num;
                cache2.put(key1, cache2.getOrDefault(key1, 0) + cache1.get(sum));
                int key2 = sum - num;
                cache2.put(key2, cache2.getOrDefault(key2, 0) + cache1.get(sum));
            }
            cache1 = cache2;
        }

        return cache1.getOrDefault(target, 0);
    }
}

// Idea: iterative dynamic programming
//
// nums: 1 2 3 4 5
//  tgt: 3
//
// One of solutions is `+1-2+3-4+5`.
// The positive subset: P = [1, 3, 4]
// The negitive subset: N = [2, 4]
// 
//                   sum(P) - sum(N) = tgt
// sum(P) + sum(N) + sum(P) - sum(N) = tgt + sum(p) + sum(N)
//                        2 * sum(P) = tgt + sum(nums)
// Find a subset p of nums such that `sum(P) = (tgt + sum(nums)) / 2`.
// It is the same with the 0/1 knapsack problem.

// 4ms 93.98% 41.1MB 80.48%
// iterative dynamic programming
// O(NT) O(T)
// N: nums len
// T: target
class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length, sum = Arrays.stream(nums).sum();

        // edge case: target이 총합보다 클 수 없으며, sum + target이 짝수가 되어야 한다
        if (sum < Math.abs(target) || (sum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (sum + target) / 2;

        // 이제 문제는 subset sum 문제로 변환된다
        int[] cache = new int[subsetSum + 1];
        cache[0] = 1; // 부분 집합 합이 0인 경우 하나의 경우가 있음

        for (int num : nums) {
            for (int amt = subsetSum; amt >= num; --amt) {
                cache[amt] += cache[amt - num];
            }
        }

        return cache[subsetSum];
    }
}
