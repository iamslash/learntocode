// Copyright (C) 2024 by iamslash

import java.util.*;

// n: 12
//    10 9 8 7 6 5 4 2 1 0

// 0ms 100.00% 40.8MB 10.45%
// math
// O(1) O(1)
class Solution {
    public boolean canAliceWin(int n) {
        int cnt = 10;
        
        while (n - cnt >= 0) {
            n -= cnt;
            cnt--;
        }
        
        return cnt % 2 == 1;
    }
}
