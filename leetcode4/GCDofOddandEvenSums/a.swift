/* Copyright (C) 2025 by iamslash */

import Foundation

// 0ms 100.00% 19.62MB 100.00%
// math
// O(1) O(1)
class Solution {
    private func gcd(_ a: Int, _ b: Int) -> Int {
        if b == 0 {
            return abs(a)
        }
        return gcd(b, a % b)      
    }
    
    func gcdOfOddEvenSums(_ n: Int) -> Int {
        let nn = n + n
        let sum = nn * (nn + 1) / 2
        let sumOdd = (sum - n) / 2
        let sumEvn = sumOdd + n

        return gcd(sumEvn, sumOdd)
    }
}
