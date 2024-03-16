// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea:
//
// Handling Edge Cases: First, we need to handle the edge cases, such
// as when the output exceeds the bounds of a 32-bit signed integer.
//
// Optimizing Division: To optimize the division, we increment the
// divisor exponentially until it surpasses the dividend and then
// subtract the largest possible multiple of the divisor from the
// dividend. We repeat this process until the dividend is smaller than
// the original divisor.
//
// Maintaining Sign: We need to carefully manage the sign of the
// result, as either the dividend or divisor (or both) can be
// negative.
//

// math
// O(lgN) O(1)
class Solution {
    public int divide(int dividend, int divisor) {
        // Handling overflow: if dividend is Integer.MIN_VALUE and divisor is -1, the result overflows.
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        // Determine the sign of the result based on the signs of dividend and divisor
        boolean negative = (dividend < 0) ^ (divisor < 0);
        
        // Convert both numbers to negative for easier handling of edge cases (overflow can only happen with Integer.MIN_VALUE)
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        
        int result = 0;
        while (dividend <= divisor) {
            int tempDivisor = divisor;
            int multiple = 1;
            // Check if doubling the current divisor and multiple is possible without going beyond the dividend
            while (dividend - tempDivisor <= tempDivisor) {
                tempDivisor <<= 1; // Equivalent to tempDivisor = tempDivisor * 2;
                multiple <<= 1; // Equivalent to multiple = multiple * 2;
            }
            // Subtract the largest found divisor multiple from the dividend
            dividend -= tempDivisor;
            // Add the corresponding multiple to the result
            result += multiple;
        }
        
        // If the result should be negative, convert it; otherwise, return the positive value
        return negative ? result : -result;
    }
}
