// Copyright (C) 2023 by iamslash

//                     i
// nums: 3 4 5 1 2 3 4 5 1 2
//       
//  cnt:

import java.util.*;


//        i
// nums: 63 51 65 87 6 17 32 14 42 46

// 1ms 100.00% 41.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
    public int minimumRightShifts(List<Integer> nums) {
        int n = nums.size(), beg = -1;
        for (int i = 1; i < n; ++i) {
            if (nums.get(i-1) > nums.get(i)) {
                beg = i;
                break;
            }
        }
        if (beg < 0) {
            return 0;
        }
        for (int i = beg + 1; i < n; ++i) {
            if (nums.get(i-1) > nums.get(i)) {
                return -1;
            }
        }
        if (nums.get(0) < nums.get(n-1)) {
            return -1;
        }
        return n - beg;
    }
}
