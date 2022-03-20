// Copyright (C) 2022 by iamslash

import java.util.*;


// i
// 3 1 2 4
// 

// 975ms 5.02% 62.2MB 55.50%
// math
// O(N^2) O(1)
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007;
        long sum = 0;
        int n = A.length, l, r;
        for (int i = 0; i < n; ++i) {
            l = i - 1; r = i + 1;
            while (l >= 0 && A[l] > A[i]) {
                --l;
            }
            while (r < n && A[r] >= A[i]) {
                ++r;
            }
            sum += (long)A[i] * (i-l) * (r-i);
            sum %= MOD;
        }
        return (int)sum;    
    }
}

// 11ms 99.27% 63.6MB 50.79%
// math
// O(N^2) O(N)
class Solution {
    public int sumSubarrayMins(int[] A) {
        int MOD = 1_000_000_007, n = A.length;
        long sum = 0;
        int[] nums = new int[n+1];
        int[] minIdxs = new int[n+1];
        int[] sums = new int[n+1];
        System.arraycopy(A, 0, nums, 1, n);
        for (int i = 1; i <= n; ++i) {
            int num = nums[i], minIdx = i - 1;
            while (nums[minIdx] >= num) {
                minIdx = minIdxs[minIdx];
            }
            minIdxs[i] = minIdx;
            sums[i] = num * (i - minIdx) + sums[minIdx];
            sum = (sum + sums[i]) % MOD;
        }
        return (int)sum;
    }
}

// 124ms 15.37% 66.1MB 45.42%
// mono stack
// O(N) O(1)
class Solution {
    public int sumSubarrayMins(int[] nums) {
        int MOD = 1_000_000_007;
        int n = nums.length, j, k;
        long sum = 0;
        Stack<Integer> stck = new Stack<>();
        for (int i = 0; i <= n; ++i) {
            while (!stck.isEmpty() &&
                   nums[stck.peek()] > (i == n ? Integer.MIN_VALUE : nums[i])) {
                j = stck.pop();
                k = stck.isEmpty() ? -1 : stck.peek();
                sum += (long)nums[j] * (j - k) * (i - j);
                sum %= MOD;
            }
            stck.push(i);
        }
        return (int)sum;
    }
}
