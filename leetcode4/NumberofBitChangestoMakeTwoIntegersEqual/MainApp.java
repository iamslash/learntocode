// Copyright (C) 2024 by iamslash

import java.util.*;

//       i
// n: 1110
// k: 1101

//       i
// n:   1011
// k: 111100

// 0ms 100.00% 40.8MB 54.58%
// bit manipulation
// O(N) O(1)
class Solution {
    public int minChanges(int n, int k) {
        int cnt = 0;

        while (n > 0 || k > 0) {
            int a = n % 2, b = k % 2;

            if (a == 0 && b == 1) {
                return -1;
            } else if (a == 1 && b == 0) {
                cnt++;
            }
            
            n >>= 1;
            k >>= 1;
        }

        return cnt;        
    }
}
