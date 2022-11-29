// Copyright (C) 2022 by iamslash

import java.util.*;

// 0ms 100.00% 41MB 42.43%
// math
// O(1) O(1)
class Solution {
    public int numberOfCuts(int n) {
        if (n == 1) {
            return 0;
        }
        return n % 2 == 0 ? n / 2 : n;
    }
}
