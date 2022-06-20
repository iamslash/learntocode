// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 41.5MB 45.04%
// math
// O(1) O(1)
class Solution {
    public int minimumNumbers(int num, int k) {
        if (num == 0) {
            return 0;
        }
        for (int i = 1; i * k <= num && i <= 10; ++i) {
            if (k * i % 10 == num % 10) {
                return i;
            }
        }
        return -1;
    }
}
