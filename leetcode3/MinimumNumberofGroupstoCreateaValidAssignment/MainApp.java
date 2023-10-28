// Copyright (C) 2023 by iamslash

import java.util.*;

//     nums: 3 2 3 2 3
//           2 3
//             i
//  minFreq: 2

//     nums: 1 1 3 10 10 10
//           2 1 3
//           i
//  minFreq: 1

// 33ms 93.13% 61.3MB 24.37%
// hash map
// O(N) O(N)
// difficult to understand
class Solution {
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> freqMap = new HashMap<>();
        for(int num : nums) {
            freqMap.put(num, freqMap.getOrDefault(num, 0) + 1);
        }
        
        int minFreq = nums.length;
        for(int freq : freqMap.values()) {
            minFreq = Math.min(minFreq, freq);
        }

        for(int freq = minFreq; freq >= 1; --freq) {
            int numGroups = groupify(freqMap, freq); 
            if(numGroups > 0) {
                return numGroups;
            }
        }
        
        return nums.length;
    }
    
    private int groupify(Map<Integer, Integer> freqMap, int bnd) {
        int groups = 0;
        int next = bnd + 1;
        
        for(int value : freqMap.values()) {
            int numGroups = value / next;
            int remaining = value % next;

            if(remaining == 0) {
                groups += numGroups;
            } else if(numGroups >= bnd - remaining) {
                groups += numGroups + 1;
            } else {
                return 0;
            }
        }
        return groups;
    }
}
