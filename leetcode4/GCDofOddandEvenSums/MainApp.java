// Copyright (C) 2025 by iamslash


// gcd(10, 5)
// gcd(5, 0)
// 5

// gcd(5, 10)
// gcd(10, 5)
// gcd(5, 0)
// 5

// gcd(2, 3)
// gcd(3, 2)
// gcd(2, 1)
// gcd(1, 0)
// 1

// 1ms 100.00%
// math
// O(1) O(1)
class Solution {

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    
    public int gcdOfOddEvenSums(int n) {
        int nn = n + n;
        int sum = nn * (nn + 1) / 2;

        int sumOdd = (sum - n) / 2;
        int sumEven = sumOdd + n;

        return gcd(sumEven, sumOdd);
    }
}
