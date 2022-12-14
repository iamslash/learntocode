// Copyright (C) 2022 by iamslash

import java.util.*;

// 104ms 78.75% 92.7MB 80.00%
// graph
// O(NlgN) O(N)
class Solution {
    public int maxStarSum(int[] vals, int[][] edges, int k) {
        int n = vals.length;
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            int u = edge[0], v = edge[1];
            graph.get(u).add(vals[v]);
            graph.get(v).add(vals[u]);
        }
        for (List<Integer> neighbors : graph) {
            Collections.sort(neighbors, Collections.reverseOrder());
        }
        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            int end = Math.min(k, graph.get(i).size());
            int sum = vals[i];
            for (int j = 0; j < end; ++j) {
                if (graph.get(i).get(j) <= 0) {
                    break;
                }
                sum += graph.get(i).get(j);
            }
            maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}
