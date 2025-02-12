// Copyright (C) 2025 by iamslash

import java.util.*;

// 5ms 80.95% 44.88MB 90.48%
// hash set
// O(N) O(1)
class Solution {
    public int maxStudentsOnBench(int[][] students) {
        int maxCnt = 0, n = students.length;
        Set<Integer>[] benchSet = new HashSet[101];

        for (int i = 0; i < benchSet.length; ++i) {
            benchSet[i] = new HashSet<>();
        }

        for (int i = 0; i < n; ++i) {
            
            benchSet[students[i][1]].add(students[i][0]);
        }

        for (int i = 0; i < benchSet.length; ++i) {
            maxCnt = Math.max(maxCnt, benchSet[i].size());
        }

        return maxCnt;
    }
}
