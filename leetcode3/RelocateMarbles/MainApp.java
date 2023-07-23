// Copyright (C) 2023 by iamslash

import java.util.*;

class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        int n = nums.length;
        Map<Integer, List<Integer>> numMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            numMap.putIfAbsent(nums[i], new ArrayList<>());
            numMap.get(nums[i]).add(i);
        }
        List<Integer> ans = new ArrayList<>();
        return ans;
    }
}
