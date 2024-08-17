// Copyright (C) 2024 by iamslash

import java.util.*;

//          
// queries: 3 3 2
//         i
//   moved: t t t
//              .
// windows: 1 2 3
//          i
//     ans: 2 3 1 

// 4ms 100.00% 68.3MB 25.00%
// backward traversal
// O(N) O(N)
class Solution {
    public int[] simulationResult(int[] windows, int[] queries) {
        int n = windows.length, m = queries.length;
        int[] ans = new int[n];
        boolean[] moved = new boolean[n];
        int pos = 0;

        for (int i = m - 1; i >= 0; --i) {
            int query = queries[i];
            if (!moved[query - 1]) {
                moved[query - 1] = true;
                ans[pos++] = query;
            }
        }

        for (int i = 0; i < n; ++i) {
            int wnd = windows[i];
            if (!moved[wnd - 1]) {
                moved[wnd - 1] = true;
                ans[pos++] = wnd;
            }
        }

        return ans;        
    }
}
