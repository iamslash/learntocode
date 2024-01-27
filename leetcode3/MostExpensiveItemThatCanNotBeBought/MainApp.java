// Copyright (C) 2024 by iamslash

import java.util.*;

// Idea: math
//
// https://en.wikipedia.org/wiki/Coin_problem
// p1 * p2 - p1 - p2

// 0ms 100.00% 40.9MB 61.87%
// math
// O(1) O(1)
class Solution {
    public int mostExpensiveItem(int p1, int p2) {
        return p1 * p2 - p1 - p2;
    }
}
