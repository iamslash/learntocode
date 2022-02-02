// Copyright (C) 2022 by iamslash

import java.util.*;

// 162ms 49.74% 169.2MB 34.99%
// hash map
// O(N) O(N)
class Solution {
    public List<Integer> findLonely(int[] nums) {
        Map<Integer, Integer> numMap = new HashMap<>();
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1);
        }
        List<Integer> ans = new ArrayList<>();
        for (int num : nums) {
            if (numMap.get(num) > 1) {
                continue;
            }
            if (!numMap.containsKey(num-1) &&
                !numMap.containsKey(num+1)) {
                ans.add(num);
            }
        }
        return ans;
    }
}

// 108ms 64.73% 217MB 5.06%
// hash map
// O(N) O(1)
class Solution {
    public List<Integer> findLonely(int[] nums) {
        int[] freqs = new int[1000001];
        List<Integer> ans = new ArrayList<>();
        for (int num : nums) {
            if (num > 0) {
                freqs[num-1]++;
            }
            freqs[num]++;
            if (num < 1000000) {
                freqs[num+1]++;
            }
        }
        for (int num : nums) {
            if (freqs[num] == 1) {
                ans.add(num);
            }
        }
        return ans;
    }
}
