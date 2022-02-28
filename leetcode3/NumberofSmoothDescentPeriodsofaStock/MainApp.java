// Copyright (C) 2022 by iamslash

import java.util.*;

// gussian summation
// sum = n*(n+1)/2

//               i
// prices: 3 2 1 4
//                 j

// 5ms 46.44% 94.4MB 66.56%
// two pointers, math
// O(N) O(1)
class Solution {
    public long getDescentPeriods(int[] prices) {
        int i = 0, n = prices.length;
        long cnt = 0;
        while (i < n) {
            int j = i+1;
            while (j < n && prices[j-1] - prices[j] == 1) {
                ++j;
            }
            long len = j - i;
            cnt += len * (len + 1) / 2;
            i = j;
        }
        return cnt;
    }
}

// 3ms 84.52% 95.8MB 62.85%
// memoization
// O(N) O(1)
class Solution {
    public long getDescentPeriods(int[] prices) {
        int n = prices.length;
        long cnt = 1;
        int len = 1;
        for (int i = 1; i < n; ++i) {
            if (prices[i-1] - prices[i] == 1) {
                len++;
            } else {
                len = 1;
            }
            cnt += len;
        }
        return cnt;
    }
}

