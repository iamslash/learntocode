// Copyright (C) 2025 by iamslash

import java.util.*;

// 0ms 100.00% 40.65MB 100.00%
// math
// O(1) O(1)
class Solution {
    public int maxContainers(int n, int w, int maxWeight) {
        int cnt = maxWeight / w;
        cnt = Math.min(n * n, cnt);
        return cnt;
    }
}
