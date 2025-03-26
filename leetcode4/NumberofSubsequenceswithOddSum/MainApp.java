// Copyright (C) 2025 by iamslash

import java.util.*;

// nums: 1 1 1
// 
//       1
//         1
//           1
//       1 1 1

// Idea: recursive dynamicprogramming
//
//           i
// nums: 1 1 1
//
// dfs(0,0)
//   dfs(0,1): 2 
//     dfs(0,2): 1
//       dfs(0,3): 0
//       dfs(1,3): 1
//     dfs(1,2): 1
//       dfs(1,3): 1
//       dfs(0,3): 0
//   dfs(1,1)
//     dfs(1,2): 1
//     dfs(0,2): 
//
// 36ms 40.00% 77.23MB 20.00%
// recursive dynamicprogramming
// O(2^N) O(N)
class Solution {

    private int dfs(int[] nums, int[][] cache, int parity, int i) {
        int mod = 1_000_000_007;
        // base
        int n = nums.length;
        if (i >= n) {
            return parity; 
        }
        
        // memo
        if (cache[parity][i] >= 0) {
            return cache[parity][i];
        }
        
        // recursion
        int cnt = dfs(nums, cache, parity, i + 1);
        cnt %= mod;
        cnt += dfs(nums, cache, (parity + nums[i]) % 2, i + 1);
        cnt %= mod;

        return cache[parity][i] = cnt;
    }
    
    public int subsequenceCount(int[] nums) {
        int n = nums.length;
        int[][] cache = new int[2][n];

        Arrays.fill(cache[0], -1);
        Arrays.fill(cache[1], -1);

        return dfs(nums, cache, 0, 0);
    }
}


// nums: 1 1 1
//     i
//  cnt: 0 
// comb: 1

// Idea: iterative dynamic programming
//
//  cnt: The number of subsequences with an odd sum
// comb: The total number of possible subsequences up to the num
//
//
// When nums[i] is even:
// - Adding an even number to existing subsequences with odd sums
// doesn't change their parity.
// - Also, not adding the even number to existing subsequences with odd
// sums still maintains their odd sum.
// - Therefore, for each subsequence with an odd sum, we have 2 choices,
// which is why cnt = (cnt << 1) % mod doubles the count.
//
// When nums[i] is odd:
// - Adding an odd number to existing subsequences with even sums
// results in odd sums.
// - Adding an odd number to existing subsequences with odd sums results
// in even sums.
// - Therefore, new subsequences with odd sums come from "existing
// subsequences with even sums + current odd number".
// - The count of subsequences with even sums is calculated as comb -
// cnt (total - odd sum count).
// - That's why we update the count of odd sum subsequences with cnt +=
// (comb - cnt) % mod.
//    
//
// 7ms 100.00% 55.62MB 100.00%
// iterative dynamic programming
// O(N) O(1)
class Solution {
    public int subsequenceCount(int[] nums) {
        int mod = 1_000_000_007;
        int cnt = 0, comb = 1, n = nums.length;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                cnt = (cnt << 1) % mod;
            } else {
                cnt += (comb - cnt) % mod;
            }

            comb = (comb << 1) % mod;
        }

        return cnt;
    }
}


