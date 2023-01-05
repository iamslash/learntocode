// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// 4 is special

// 1ms 93.20% 39.5MB 75.08%
// math
// O(N) O(N)
class Solution {
    private List<Integer> primeFacotorize(int num) {
        int sqrtNum = (int)Math.sqrt(num);
        List<Integer> rst = new ArrayList<>();
        while (num % 2 == 0) {
            rst.add(2);
            num /= 2;
        }        
        for (int p = 3; p <= sqrtNum; p += 2) {
            while (num % p == 0) {
                rst.add(p);
                num /= p;
            }
        }
        if (num > 1) {
            rst.add(num);
        }
        return rst;
    }
    public int smallestValue(int n) {
        if (n <= 4) {
            return n;
        }
        List<Integer> primes;
        while (true) {            
            primes = primeFacotorize(n);
            // System.out.println(primes);
            if (primes.size() == 1) {
                break;
            }
            int sum = 0;
            for (int prime : primes) {
                sum += prime;
            }
            n = sum;
        }
        return primes.get(0);
    }
}
