// Copyright (C) 2023 by iamslash

import java.util.*;

// 4ms 66.67% 40.1MB 44.44%
// brute force
// O(N) O(1)
class Solution {
    public int sumOfMultiples(int n) {
        int sum = 0;
        for (int a = 1; a <= n; ++a) {
            if (a % 3 == 0 ||
                a % 5 == 0 ||
                a % 7 == 0) {
                sum += a;
            }
        }
        return sum;
    }
}

// n: 16
// 1
// 2
// 3  : 3
// 4
// 5  : 5
// 6  : 3 3
// 7
// 8
// 9  : 3 3 3
// 10 : 5 5
// 11
// 12 : 3 3 3 3
// 13
// 14
// 15 : 3 3 3 3 3
//      5 5 5
// 16

// 1ms 100.00% 40.2B 11.11%
// greedy
// O(1) O(1)
class Solution {
    public int divisible(int n, int d) {
        int cnt = n / d;
        return d * cnt * (cnt + 1) / 2;
    }
    public int sumOfMultiples(int n) {
        return divisible(n, 3) +
            divisible(n, 5) +
            divisible(n, 7) -
            divisible(n, 15) -
            divisible(n, 21) -
            divisible(n, 35) +
            divisible(n, 105);
    }
}
