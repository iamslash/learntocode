// Copyright (C) 2024 by iamslash

// 0ms 100.00% 40.2MB 66.67%
// math
// O(N) O(1)
class Solution {
    public int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, num = x;
        while (num > 0) {
            sum += (num % 10);
            num /= 10;
        }
        // System.out.printf("x: %d, sum: %d\n", x, sum);
        if (x % sum == 0) {
            return sum;
        }
        return -1;
    }
}
