// Copyright (C) 2022 by iamslash

import java.util.*;

// Idea: double DFS
//
// out degree is 1 at most.

// 8ms 98.42% 58.4MB 95.89%
// double DFS
// O(N) O(N)
class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int ans = -1, minDist = Integer.MAX_VALUE, n = edges.length;
        int[] C1 = new int[n], C2 = new int[n];
        Arrays.fill(C1, -1);
        Arrays.fill(C2, -1);
        for (int u = node1, dist = 0; u != -1 && C1[u] == -1; u = edges[u]) {
            C1[u] = dist++;
        }
        for (int u = node2, dist = 0; u != -1 && C2[u] == -1; u = edges[u]) {
            C2[u] = dist++;
            if (C1[u] >= 0 && Math.max(C1[u], C2[u]) <= minDist) {
                ans = Math.max(C1[u], C2[u]) == minDist ? Math.min(u, ans) : u;
                minDist = Math.max(C1[u], C2[u]);
            }
        }
        return ans;
    }
}
