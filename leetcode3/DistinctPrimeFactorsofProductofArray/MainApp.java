// Copyright (C) 2023 by iamslash

import java.util.*;

// 18ms 81.04% 43.5MB 25.05%
// math
// O(N) O(N)
class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> primeSet = new HashSet<>();
        for (int num : nums) {
            int sqrtnum = (int)Math.sqrt(num);
            while (num % 2 == 0) {
                primeSet.add(2);
                num /= 2;
            }
            for (int p = 3; p <= sqrtnum; p += 2) {
                while (num % p == 0) {
                    primeSet.add(p);
                    num /= p;
                }
            }
            if (num > 1) {
                primeSet.add(num);
            }
        }
        // System.out.println(primeSet);
        return primeSet.size();
    }
}
