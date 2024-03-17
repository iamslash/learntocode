// Copyright (C) 2024 by iamslash

import java.util.*;

// 1ms 100.005 42.6MB 50.00%
// math
// O(N) O(1)
class Solution {

    private  int encrypt(int num) {
        int rst = 0, digitCnt = 0, maxDigit = 0;

        while (num > 0) {
            digitCnt++;
            maxDigit = Math.max(maxDigit, num % 10);
            num /= 10;
        }
        
        while (digitCnt-- > 0) {
            rst = rst * 10 + maxDigit;
        }

        return rst;
    }
    
    public int sumOfEncryptedInt(int[] nums) {
        int sum = 0;

        for (int num : nums) {
            sum += encrypt(num);
            
            // System.out.printf("num: %d, sum: %d\n", num, sum);
        }

        return sum;
    }
}
