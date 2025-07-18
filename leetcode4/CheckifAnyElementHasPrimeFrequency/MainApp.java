// Copyright (C) 2025 by iamslash

import java.util.*;

// 2ms 74.71% 42.84MB 62.02%
// hash map
// O(N) O(N)
class Solution {

    private boolean isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        for (int p = 3; p * p <= num; p += 2) {
            if (num % p == 0) {
                return false;
            }
        }

        return true;
    }
    
    public boolean checkPrimeFrequency(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for (int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }

        for (int freq : freqMap.values()) {
            if (isPrime(freq)) {
                return true;
            }
        }

        return false;        
    }
}
