// Copyright (C) 2023 by iamslash

import java.util.*;

// 54ms 28.10% 54.8MB 99.22%
// hash map
// O(N) O(N)
class Solution {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> cntMap = new HashMap<>();
        int n = nums.size(), majNum = 0;
        for (int num : nums) {
            cntMap.put(num, cntMap.getOrDefault(num, 0) + 1);
            if (majNum == 0 || cntMap.get(num) > cntMap.get(majNum)) {
                majNum = num;
            }
        }
        int majCnt = cntMap.get(majNum), curCnt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums.get(i) == majNum) {
                curCnt++;
            }
            int remCnt = majCnt - curCnt;
            if (curCnt * 2 > i + 1 && remCnt * 2 > n - i - 1) {
                return i;
            }
        }
        return -1;
    }
}
