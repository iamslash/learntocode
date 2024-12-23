// Copyright (C) 2024 by iamslash

import java.util.*;

// 4ms 37.02% 44.3MB 91.19%
// hash set
// O(N) O(N)
class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> numSet = new HashSet<>();
        
        for (int num : nums) {
            numSet.add(num);
        }

        int cnt = 0;
        for (int num : numSet) {
            if (num < k) {
                return -1;
            }
            if (num > k) {
                cnt++;
            }
        }

        return cnt;
    }
}

// 1ms 100.00% 44.7MB 62.98%
// hash map
// O(N) O(N)
class Solution {
    public int minOperations(int[] nums, int k) {
        int[] numCnts = new int[101];

        for (int num : nums) {
            if (num < k) {
                return -1;
            }
            if (num > k) {
                numCnts[num]++;
            }
        }

        int cnt = 0;
        for (int num = 0; num <= 100; ++num) {
            if (numCnts[num] > 0) {
                cnt++;
            }
        }

        return cnt;

    }
}
