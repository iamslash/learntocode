// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: eratothenes
//
// p * q (p <= q)
//
// 0 1 2 3 4 5 6 7 8 9 10
// f f t t t t t t t t  t
//     .
// 0 1 2 3 4 5 6 7 8 9 10
// f f t t f t f t f t  f
//       .
// 0 1 2 3 4 5 6 7 8 9 10
// f f t t f t f t f f  f

// 4ms 87.38% 42.9MB 45.21%
// eratosthenes
// O(N) O(1)
class Solution {
    private void dump(int[] A) {
        for (int a : A) {
            System.out.printf("%d ", a);
        }
        System.out.println("");
    }    
    public boolean primeSubOperation(int[] nums) {        
        boolean[] primes = new boolean[1001];
        Arrays.fill(primes, true);
        primes[0] = primes[1] = false;
        for (int p = 2; p * p <= 1000; ++p) {
            if (primes[p]) {
                for (int q = p * p; q <= 1000; q += p) {
                    primes[q] = false;
                }
            }
        }
        dump(primes);
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            int tgt = nums[i] - 1;
            if (i > 0) {
                tgt -= nums[i-1];
            }
            if (tgt < 0) {
                return false;
            }
            while (tgt > 0 && !primes[tgt]) {
                tgt--;                
            }
            nums[i] -= tgt;
            if (i > 0 && nums[i - 1] >= nums[i]) {
                return false;
            }
        }
        return true;
    }
}
