// Copyright (C) 2023 by iamslash

import java.util.*;

//         i
//   nums: 2 2 3 3 3 3 2
// idxMap: 2 3 
//         0 2 
//         1 3 
//         6 4 
//         9 5
//           10


// Idea: hash map
//
// idxMap: {num : [idxs]}
// Add the distance from the last idx to the first idx.
// The max distance is the seconds.
// The answer is min of max distances for each num.

// 685ms 5.03% 78.1MB 61.53%
// hash map
// O(N) O(N)
class Solution {
    public int minimumSeconds(List<Integer> nums) {
        int n = nums.size(), ans = n;
        Map<Integer, List<Integer>> idxMap = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            idxMap.putIfAbsent(nums.get(i), new ArrayList<>());
            idxMap.get(nums.get(i)).add(i);
        }
        for (List<Integer> idxList : idxMap.values()) {
            idxList.add(idxList.get(0) + n);
            int maxLen = 0;
            for (int i = 1; i < idxList.size(); ++i) {
                maxLen = Math.max(maxLen, (idxList.get(i) - idxList.get(i - 1)));
            }
            ans = Math.min(ans, maxLen / 2);
        }
        return ans;
    }
}
