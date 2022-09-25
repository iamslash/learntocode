// Copyright (C) 2022 by iamslash

import java.util.*;

// 6ms 100.00% 42.9MB 100.00%
// hash map, sort
// O(NlgN) O(N)
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = heights.length;
        Map<Integer, String> hight2nameMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            hight2nameMap.put(heights[i], names[i]);
        }
        Arrays.sort(heights);
        for (int i = 0; i < n; ++i) {
            names[i] = hight2nameMap.get(heights[n-1-i]);
        }
        return names;
    }
}
