// Copyright (C) 2025 by iamslash

import java.util.*;

//       k: 2
// queries: 1,2 3,4 2,3 -3,0
//                         i
//      pq:   3 3 5 7

// 121ms 37.04% 142.78MB 73.46%
// heap
// O(NlgN) O(K)
class Solution {
    public int[] resultsArray(int[][] queries, int k) {
        int n = queries.length;
        int[] ans = new int[n];
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n; ++i) {
            
            int x = queries[i][0], y = queries[i][1];
            int dist = Math.abs(x) + Math.abs(y);

            pq.offer(dist);
            if (pq.size() > k) {
                pq.poll();
            }

            ans[i] = pq.size() == k ? pq.peek() : -1;
        }

        return ans;
    }
}
