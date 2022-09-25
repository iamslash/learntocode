// Copyright (C) 2022 by iamslash

import java.util.*;

// 17ms 70.00% 55MB 70.00%
// sort
// O(NlgN) O(N)
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int n = names.length;
        Integer[] idxs = new Integer[n];
        for (int i = 0; i < n; ++i) {
            idxs[i] = i;
        }
        Arrays.sort(idxs, (i, j) -> heights[j] - heights[i]);
        String[] ans = new String[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = names[idxs[i]];
        }
        return ans;
    }
}
