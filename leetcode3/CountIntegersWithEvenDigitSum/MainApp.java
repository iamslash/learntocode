// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 75.00% 41.3MB 25.00%
// brute force
class Solution {
    private boolean evenDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum % 2 == 0;
    }
    public int countEven(int bnd) {
        int cnt = 0;
        for (int num = 1; num <= bnd; ++num) {
            if (evenDigitSum(num)) {
                cnt++;
            }
        }
        return cnt;
    }
}

// https://leetcode.com/problems/count-integers-with-even-digit-sum/discuss/1784826/Java-O(1)-Solution-Only-check-one-number
// 0ms 100.00% 39.2MB 75.00%
// math
// O(1) O(1)
class Solution {
    private boolean evenDigitSum(int num) {
	// Digit sum of the last number, we can get each digit this way sicne the range is [1, 1000]
	int sum = num % 10 + (num / 10) % 10 + (num / 100) % 10 + (num / 1000) % 10;

	// Check the parity of the digit sum of the last number
	return (num - (sum & 1)) / 2;    }
}
