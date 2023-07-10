// Copyright (C) 2023 by iamslash

import java.util.*;

//      x: 5
//      n: 3
//                   i
//   logs: 1,3 1,5 2,6
//                   j
// cntMap: 1 2
//         1 1
//            k
//   qrys: 5,10 6,11
//
//

//      x: 2
//      n: 3
//                         i
//   logs: 2,1 3,1 1,2 2,4 
//                   j
// cntMap: 1 2 3
//         1 1 0
//               i
//   qrys: 1,3 2,4
//    ans:   0

// sort, sliding window
// O(NlgN) O(N)
class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);
        Map<Integer, Integer> cntMap = new HashMap<>();
        int m = queries.length, i = 0, j = 0;
        int[] ans = new int[m];
        for (int k = 0; k < m; ++k) {
            int fr = queries[k] - x;
            int to = queries[k];
            // Add server count 
            while (i < n && logs[i][1] <= to) {
                cntMap.put(logs[i][0], cntMap.getOrDefault(logs[i][0], 0) + 1);
                i++;
            }
            // Sub server count
            while (j < n && logs[j][1] < fr) {
                cntMap.put(logs[j][0], cntMap.get(logs[j][0]) - 1);                
                if (cntMap.get(logs[j][0]) == 0) {
                    cntMap.remove(logs[j][0]);
                }
                j++;
            }
            ans[k] = n - cntMap.size();
        }
        return ans;
    }
}
