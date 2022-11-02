// Copyright (C) 2022 by iamslash

// 175ms 88.88% 41.3MB 50.41%
// brute force
// O(N) O(1)
class Solution {
    private int reverse(int num) {
        int rst = 0;
        while (num > 0) {
            rst = (rst * 10) + (num % 10);
            num /= 10;
        }
        return rst;
    }
    public boolean sumOfNumberAndReverse(int num) {
        int half = num / 2;
        for (int a = half; a <= num; ++a) {
            if (a + reverse(a) == num) {
                return true;
            }
        }
        return false;
    }
}
