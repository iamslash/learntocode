// Copyright (C) 2025 by iamslash


// Idea: math
//
// A = a * gcd
// B = b * gcd
// A * B = a * b * gcd * gcd
//       = lcm * gcd
// lcm = A * B / gcd
//
// C = c * gcd
// A * B * C = (A * B) * C
//           = lcm(A * B, C) * gcd(A * B, C)
//

// 3ms 90.62% 42.43MB 80.63%
// brute force
// O(N^2) O(1)
class Solution {

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    private int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
    
    public int maxLength(int[] nums) {
        int n = nums.length, maxLen = 1;

        for (int i = 0; i < n; ++i) {
            int prdNum = nums[i];
            int gcdNum = nums[i];
            int lcmNum = nums[i];
            
            for (int j = i + 1; j < n; ++j) {
                gcdNum = gcd(gcdNum, nums[j]);
                prdNum *= nums[j];
                lcmNum = lcm(lcmNum, nums[j]);

                if (lcmNum * gcdNum == prdNum) {
                    maxLen = Math.max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
}
