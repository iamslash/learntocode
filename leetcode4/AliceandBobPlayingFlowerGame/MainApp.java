// Copyright (C) 2024 by iamslash

// n: 3
// m: 2

// Idea: math
//
//       n     m
// 0. even, even: loose
// 1. even,  odd:  win
// 2. odd,  even:  win
// 3. odd,   odd: loose
//
// odd, even: (n / 2 + n % 2) * (m / 2) 
// even, odd: (n / 2) * (m / 2 + m % 2)
//       ans: (n / 2 + n % 2) * (m / 2) +
//            (n / 2) * (m / 2 + m % 2)
//          = (m * n / 4) + (n % 2) * (m / 2) + (m % 2) * (n / 2)
//          = (m * n / 4) + (m * n / 4) ???
//          = m * n / 2 

// 0ms 100.00% 40.6MB 55.58%
// math
// O(1) O(1)
class Solution {
    public long flowerGame(long n, long m) {
        return m * n / 2;
    }
}
