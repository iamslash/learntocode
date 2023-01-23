// Copyright (C) 2023 by iamslash

import java.util.*;

// n: 2 3
//

// 0ms 100.00% 39.3MB 71.43%
// brute force
// O(N) O(1)
class Solution {
    public int alternateDigitSum(int n) {
        int sum = 0, cnt = 0, sign = 1;
        while (n > 0) {
            sum += n % 10 * sign;
            cnt++;
            sign *= -1;
            n /= 10;
            // System.out.println(sum);
        }
        return cnt % 2 == 0 ? -sum : sum;
    }
}
