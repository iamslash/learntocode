// Copyright (C) 2022 by iamslash

import java.util.*;

// nums: 9 3 8 4 2 5 3 8 6 1
//                       .

// 2ms 100.00% 45.1MB 80.00%
// brute force
// O(N) O(1)
class Solution {
    public int averageValue(int[] nums) {
        int sum = 0, cnt = 0;
        for (int num : nums) {
            if (num % 2 == 0 && num % 3 == 0) {
                sum += num;
                cnt++;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
}
