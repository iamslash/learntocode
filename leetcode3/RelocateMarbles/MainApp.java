// Copyright (C) 2023 by iamslash

import java.util.*;

// 63ms 97.59% 58.2MB 86.95%
// sort, hash set
// O(NlgN) O(N)
class Solution {
    public List<Integer> relocateMarbles(int[] nums, int[] moveFrom, int[] moveTo) {
        int n = moveFrom.length;
        Set<Integer> posSet = new HashSet<>();
        for (int pos : nums) {
            posSet.add(pos);
        }
        for (int i = 0; i < n; ++i) {
            posSet.remove(moveFrom[i]);
            posSet.add(moveTo[i]);
        }
        List<Integer> posList = new ArrayList<>(posSet);
        Collections.sort(posList);        
        return posList;
    }
}
