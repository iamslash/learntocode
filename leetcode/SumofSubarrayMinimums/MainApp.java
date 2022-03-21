// Copyright (C) 2022 by iamslash

import java.util.*;


// i
// 3 1 2 4
// 

// 975ms 5.02% 62.2MB 55.50%
// brute force
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

// 149ms 25.68% 70.4MB 39.19%
// mono stack
// O(N) O(N)
class Solution {
    public int sumSubarrayMins(int[] nums) {
        long ans = 0, MOD = 1_000_000_007;
        int n = nums.length;
        int[] lefts = new int[n], rights = new int[n];
        Stack<int[]> leftStack = new Stack<>(), rightStack = new Stack<>();
        for (int i = 0; i < n; ++i) {
            int cnt = 1;
            while (!leftStack.isEmpty() && leftStack.peek()[0] > nums[i]) {
                cnt += leftStack.pop()[1];
            }
            leftStack.push(new int[]{nums[i], cnt});
            lefts[i] = cnt;
        }
        for (int i = n-1; i >= 0; --i) {
            int cnt = 1;
            while (!rightStack.isEmpty() && rightStack.peek()[0] >= nums[i]) {
                cnt += rightStack.pop()[1];
            }
            rightStack.push(new int[]{nums[i], cnt});
            rights[i] = cnt;
        }
        for (int i = 0; i < n; ++i) {
            ans = (ans + (long)nums[i] * lefts[i] * rights[i]) % MOD;
        }
        return (int)ans;
    }
}

// 124ms 15.37% 66.1MB 45.42%
// mono stack
// O(N) O(N)
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

// difficult
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

//         i
//   nums: 3 1 2 4
//           j
//  lefts: - - 1 2 
// rights: 1 4 4 4
//           i
 
// 14ms 98.17% 63.9MB 75.96%
// hash map
// O(N) O(N)
class Solution {
    public int sumSubarrayMins(int[] nums) {
        int n = nums.length, MOD = 1_000_000_007;
        int[] lefts = new int[n], rights = new int[n];
        long ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = i - 1;
            while (j >= 0 && nums[j] > nums[i]) {
                j = lefts[j];
            }
            lefts[i] = j;
        }
        for (int i = n-1; i >= 0; --i) {
            int j = i + 1;
            while (j < n && nums[j] >= nums[i]) {
                j = rights[j];
            }
            rights[i] = j;
            // sum count
            ans = (ans + (long)nums[i] * (i - lefts[i]) * (rights[i] - i)) % MOD;
        }
        return (int)ans;
    }
}
