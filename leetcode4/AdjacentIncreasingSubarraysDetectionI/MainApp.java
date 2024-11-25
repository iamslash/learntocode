// Copyright (C) 2024 by iamslash

import java.util.*;


//    k: 3
//            i
//  nums: 2 5 7 8 9 2 3 4 3 1
// upCnt: 1 2 3
//   pre: 0 0 0
//   ans: 

// 2ms 40.77% 44.3MB 80.54%
// linear traversal
// O(N) O(1)
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {

        int n = nums.size(), upCnt = 1, preMaxUpCnt = 0, maxWnd = 0;

        for (int i = 1; i < n; ++i) {

            if (nums.get(i - 1) < nums.get(i)) {
                upCnt++;
            } else {
                preMaxUpCnt = upCnt;
                upCnt = 1;
            }

            maxWnd = Math.max(maxWnd, Math.max(upCnt / 2, Math.min(preMaxUpCnt, upCnt)));
        }

        return maxWnd >= k;
    }
}


// 1ms 100.00% 44MB 96.60%
// linear traversal
// O(N) O(1)
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int size = nums.size() - (2 * k);

        for (int i = 0; i <= size; ++i) {
            int j = i + 1, end = i + k;
            while (j < end && nums.get(j - 1) < nums.get(j)) {
                j++;
            }
            if (j < end) {
                continue;
            }

            j++;
            end += k;
            while (j < end && nums.get(j - 1) < nums.get(j)) {
                j++;
            }
            if (j == end) {
                return true;
            }
        }

        return false;
    }
}
