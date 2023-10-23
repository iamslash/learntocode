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

//     nums: 1 1 3 10 10 10
//           3 4 5
//           i
//  minFreq: 3

// Wrong answer for
// Input:
// [1,1,3,3,1,1,2,2,3,1,3,2]
// Output:
// 4
// Expected:
// 5
//    
// hash map
// O(N) O(N)
class Solution {
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int minFreq = 100_000;
        for (int num : nums) {
            int freq = cntMap.getOrDefault(num, 0) + 1;
            cntMap.put(num, freq);
        }
        for (int freq : cntMap.values()) {
            minFreq = Math.min(minFreq, freq);
        }
        System.out.println(cntMap);
        System.out.println(minFreq);
        int groupCnt = 0;
        for (int freq : cntMap.values()) {
            if (freq <= minFreq + 1) {
                groupCnt++;
            } else {
                groupCnt += ((freq + minFreq) / (minFreq + 1));
            }
        }
        return groupCnt;
    }
}


/// hash map
// O(N) O(N)
class Solution {
    private int getMinGroup(int target, int bnd) {
        int tarDiv = target / (bnd + 1);
        int k = target % (bnd + 1) == 0 ? tarDiv : tarDiv + 1;
        double upper = (double) target / bnd;
        if (k > upper) {
            return 1000_000;
        }
        return k;
    }
    public int minGroupsForValidAssignment(int[] nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int minFreq = 100_000;
        for (int num : nums) {
            int freq = cntMap.getOrDefault(num, 0) + 1;
            minFreq = Math.min(minFreq, freq);
            cntMap.put(num, freq);
        }
        int minGroupCnt = 0;
        for (int g = 1; g <= minFreq; ++g) {
            int groupCnt = 0;
            for (int freq : cntMap.values()) {
                groupCnt += getMinGroup(freq, g);
            }
            minGroupCnt = Math.min(groupCnt, minGroupCnt);
        }
        return minGroupCnt;
    }
}
