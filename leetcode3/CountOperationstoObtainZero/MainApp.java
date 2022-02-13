// Copyright (C) 2022 by iamslash

import java.util.*;

// num1: 2 2 1 0
// num2: 3 1 1 1
//
// num1: 10 9 8 7
// num2:  1 1 1 1

// 1ms 25.00% 46.2MB 25.00%
// brute force
// O(N) O(N)
class Solution {
    private int cnt = 0;
    private void count(int a, int b) {
        if (a == 0 || b == 0) {
            return;
        }
        cnt++;
        if (a >= b) {
            count(a-b, b);
        } else {
            count(a, b-a);
        }
    }
    public int countOperations(int num1, int num2) {
        count(num1, num2);
        return cnt;
    }
}

// 3ms 25.00% 40.9MB 75.00%
// brute force
// O(N) O(1)
class Solution {
    public int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
            cnt++;
        }
        return cnt;
    }
}

// 0ms 100.00% 41.2MB 50.00%
// math
// O(N) O(1)
class Solution {
    public int countOperations(int num1, int num2) {
        int cnt = 0;
        while (num1 > 0 && num2 > 0) {
            if (num1 < num2) {
                int tmp = num1;
                num1 = num2;
                num2 = tmp;
            }
            cnt += (num1 / num2);
            num1 %= num2;
        }
        return cnt;
    }
}
