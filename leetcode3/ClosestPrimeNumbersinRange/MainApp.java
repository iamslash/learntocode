// Copyright (C) 2023 by iamslash

import java.util.*;

// 1057ms 24.47% 39.7MB 98.59%
// math
// O(NM) O(N)
// N: count of nums between left and right
// M: each number
class Solution {
    private boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }
        if (num == 2) {
            return true;
        }
        if (num % 2 == 0) {
            return false;
        }
        int sqrtn = (int)Math.sqrt(num);
        for (int p = 3; p <= sqrtn; p += 2) {
            if (num % p == 0) {
                return false;
            }
        }
        return true;
    }
    public int[] closestPrimes(int left, int right) {
        int[] minDiffPrimes = new int[]{-1, -1};
        int prevPrime = -1, minDiff = right - left + 1;
        for (int num = left; num <= right; ++num) {
            if (isPrime(num)) {
                if (prevPrime < 0) {
                    prevPrime = num;
                } else {
                    if (num - prevPrime < minDiff) {
                        minDiffPrimes[0] = prevPrime;
                        minDiffPrimes[1] = num;
                        minDiff = num - prevPrime;
                    }
                }
                prevPrime = num;
            }
        }
        return minDiffPrimes;
    }
}
