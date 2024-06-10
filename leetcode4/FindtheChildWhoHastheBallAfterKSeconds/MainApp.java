// Copyright (C) 2024 by iamslash

import java.util.*;

// k: 8
// n: 5
//
// .
// 0 1 2 3 4


// 0ms 100.00% 40.4MB 95.63%
// math
// O(1) O(1)
class Solution {
    public int numberOfChild(int n, int k) {
        int quo = k / (n - 1);
        int rem = k % (n - 1);

        if (quo % 2 == 0) {
            return rem;
        }
        return n - 1 - rem;
    }
}
