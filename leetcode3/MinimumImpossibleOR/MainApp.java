// Copyright (C) 2023 by iamslash

import java.util.*;

// Idea : bit manipulation
//
// The target number is something like 1, 10, 100, 1000, etc...
// If we have 1 and 10, we can make all numbers equal less than 100.
// If we have 1, 10 and 100, we can make all numbers equal less than 1000.
// The candidates of the ans are 1, 10, 100, 1000, etc...

// 28ms 32.73% 54.7MB 65.56%
// bit manipulation
// O(N) O(N)
class Solution {
    public int minImpossibleOR(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        int maxNum = 0;
        for (int num : nums) {
            numSet.add(num);
            maxNum = Math.max(maxNum, num);
        }
        int cand = 1;
        while (cand <= maxNum) { 
            if (!numSet.contains(cand)) {
                return cand;
            }
            cand <<= 1;
        }        
        return cand;
    }
}

// 27ms 54.23% 54.4MB 83.16%
// bit manipulation, hash set
// O(N) O(N)
class Solution {
    public int minImpossibleOR(int[] nums) {
        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }
        int ans = 1;
        while (numSet.contains(ans)) {
            ans <<= 1;
        }
        return ans;
    }
}
