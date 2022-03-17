// Copyright (C) 2022 by iamslash

import java.util.*;

// 5ms 81.26% 73.4MB 56.50%
// sliding window
// O(N) O(1)
class Solution {
    public int minSwaps(int[] data) {
        int n = data.length, ones = 0, maxOnesInWnd = 0;
        for (int num : data) {
            ones += num;
        }
        for (int i = 0, onesInWnd = 0; i < n; ++i) {
            if (i >= ones) {
                onesInWnd -= data[i-ones];
            }
            onesInWnd += data[i];
            maxOnesInWnd = Math.max(maxOnesInWnd, onesInWnd);
        }
        return ones - maxOnesInWnd;
    }
}
