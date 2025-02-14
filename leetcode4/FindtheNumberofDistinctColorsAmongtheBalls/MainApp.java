// Copyright (C) 2025 by iamslash

import java.util.*;


//                              i
//     queries: [[0,1],[1,2],[2,2],[3,4],[4,5]]
// numColorMap: 0 1 2
//              1 2 2
// colorCntMap: 1 2
//              0 1
//         ans: 1 2 2

// 41ms 61.43% 98.62MB 24.45%
// hash map
// O(N) O(N)
class Solution {
    public int[] queryResults(int limit, int[][] queries) {
        int m = queries.length;
        int[] ans = new int[m];
        Map<Integer, Integer> numColorMap = new HashMap<>();
        Map<Integer, Integer> colorCntMap = new HashMap<>();

        for (int i = 0; i < m; ++i) {
            int[] query = queries[i];
            int key = query[0], val = query[1];

            if (numColorMap.get(key) != null &&
                numColorMap.get(key) > 0) {
                int prevCol = numColorMap.get(key);
                colorCntMap.put(prevCol, colorCntMap.get(prevCol) - 1);
                if (colorCntMap.get(prevCol) == 0) {
                    colorCntMap.remove(prevCol);
                }
            }
            
            numColorMap.put(key, val);
            colorCntMap.put(val, colorCntMap.getOrDefault(val, 0) + 1);
            ans[i] = colorCntMap.size();
        }

        return ans;        
    }
}
