// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 99.98% 79.1MB 69.74%
// sieve of eratosthenes
// O(N) O(1)
class Solution {
    private void dump(boolean[] primes, int end) {
        for (int i = 1; i <= end; ++i) {
            char c = primes[i] ? 't' : 'f';
            System.out.printf("%c ", c);
        }
        System.out.println();
    }
    public int maximumPrimeDifference(int[] nums) {
        boolean[] primes = new boolean[101];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;

        for (int p = 2; p * p <= 100; ++p) {
            if (!primes[p]) {
                continue;
            }
            for (int c = p * p; c <= 100; c += p) {
                primes[c] = false;
            }
        }
        
        // dump(primes, 10);

        int n = nums.length;
        int first = 0;
        for (int i = 0; i < n; ++i) {
            if (primes[nums[i]]) {
                first = i;
                break;
            }
        }
        
        int last = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (primes[nums[i]]) {
                last = i;
                break;
            }
        }
        
        // System.out.printf("first: %d, last: %d\n", first, last);

        return Math.abs(first - last);
    }
}
