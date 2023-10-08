// Copyright (C) 2023 by iamslash

import java.util.*;

// 1ms 50.00% 39.4MB 50.00%
// brute force
// O(N) O(1)
class Solution {
    public int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for (int num = 1; num <= n; ++num) {
            if (num % m != 0) {
                num1 += num;
            } else {
                num2 += num;
            }
        }
        return num1 - num2;
    }
}


// Idea: math
//
// m + 2m + 3m + .. + km
// = (1 + 2 + 3 + .. + k) * m
// = (1 + k) * k / 2 * m
// num1 - num2
// = (1 + 2 + .. n) - (m + 2m + .. + km) * 2
// = (1 + n) * n / 2 - (1 + k) * k * m
//
// 0ms 100.00% 39.4MB 50.00%
// math
// O(1) O(1)
class Solution {
    public int differenceOfSums(int n, int m) {
        int num1 = (1 + n) * n / 2;
        int num2 = (1 + n / m) * (n / m) * m; 
        return num1 - num2;
    }
}
