// Copyright (C) 2023 by iamslash

import java.util.*;


// Idea: brain teaser
//
// n % (n - 1) == 1 if n > 2
//   n - 2, n - 3, n - 4, ..., 2 
// 1 if n == 1

// 0ms 100.00% 39.5MB 42.86%
// brain teaser
// O(1) O(1)
class Solution {
    public int distinctIntegers(int n) {
        return Math.max(1, n - 1);
    }
}
