// Copyright (C) 2023 by iamslash

import java.util.*;

// 4ms 20.00% 51.9MB 100.00%
// brute force
// O(Nsqrt(N)) O(1)
class Solution {
    private boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        if (n == 2) {
            return true;
        }
        if (n % 2 == 0) {
            return false;            
        }
        int sqrtn = (int)Math.sqrt(n);
        for (int i = 3; i <= sqrtn; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    public int diagonalPrime(int[][] nums) {
        int n = nums.length, maxPrime = 0;
        for (int i = 0; i < n; ++i) {
            if (isPrime(nums[i][i])) {
                maxPrime = Math.max(maxPrime, nums[i][i]);
            }
            if (isPrime(nums[i][n-1-i])) {
                maxPrime = Math.max(maxPrime, nums[i]
                                    [n-1-i]);
            }
        }
        return maxPrime;
    }
}
