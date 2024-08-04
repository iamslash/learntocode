// Copyright (C) 2024 by iamslash

import java.util.*;

// 0ms 100.00% 44.3MB 22.47%
// math
// O(N) O(1)
class Solution {
    public boolean canAliceWin(int[] nums) {
        int singleDigitSum = 0, doubleDigitSum = 0;

        for (int num : nums) {
            if (num < 10) {
                singleDigitSum += num;
            } else {
                doubleDigitSum += num;
            }
        }

        if (singleDigitSum == doubleDigitSum) {
            return false;
        }

        return true;
    }
}
