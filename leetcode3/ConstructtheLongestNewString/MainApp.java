// Copyright (C) 2023 by iamslash

import java.util.*;

// 2ms 99.38% 40.4MB 62.42%
// greedy, math
// O(1) O(1)
class Solution {
    public int longestString(int x, int y, int z) {
        return (Math.min(x + 1, y) +
                Math.min(x, y + 1) +
                z ) * 2;
    }
}
