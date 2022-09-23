// Copyright (C) 2022 by iamslash

import java.util.*;

// 1ms 25.25% 41.8MB 6.99%
// math
// O(1) O(1)
class Solution {
    public int smallestEvenMultiple(int n) {
        if (n % 2 == 0) {
            return Math.max(n, 2);
        }
        return n * 2;
    }
}
