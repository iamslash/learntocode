// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea: math
//
// negNumCnt: negative number cnt
// maxPosNum: max positive number
// maxNegNum: max negative number
//
// 0. return 0:      -1 0   negCnt == 1 && maxNum == 0
// 1. return 0:       0     negCnt == 0 && maxNum == 0
// 2. return maxNegNum: -1  negCnt == 1 && maxNum < 0
// 3. return product: -2 -1 0 3               prod > 0 
// 4. return product / maxNegNum: -3 -2 -1    prod < 0

// 2ms 100.00% 43.4MB 38.70%
// math
// O(N) O(1)
class Solution {
    public long maxStrength(int[] nums) {
        int negNumCnt = 0, maxNum = -9, maxNegNum = -9;
        long prod = 1;
        for (int num : nums) {
            maxNum = Math.max(maxNum, num);
            if (num == 0) {
                continue;
            }
            prod *= num;
            if (num < 0) {
                negNumCnt++;
                maxNegNum = Math.max(maxNegNum, num);
            }
        }
        if (maxNum == 0 && (negNumCnt == 0 || negNumCnt == 1)) {
            return 0;
        }
        if (negNumCnt == 1 && maxNum < 0) {
            return maxNum;
        }
        if (prod > 0) {
            return prod;
        }
        return prod / maxNegNum;
    }
}
