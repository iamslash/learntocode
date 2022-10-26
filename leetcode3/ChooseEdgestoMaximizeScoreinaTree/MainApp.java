// Copyright (C) 2022 by iamslash

import java.util.*;

//          0
//     5 /     \ 10
//      1        2
//           6 /   \ 4
//            5     6
//
// without_0: with_1 + with_2 
//    with_0: max(without_1, without_2)
// 
// u: 1, rst[0]: 0 rst[1] 0
// u: 3, rst[0]: 0 rst[1] 0
// u: 4, rst[0]: 0 rst[1] 0
// u: 2, rst[0]: 0 rst[1] 6
// u: 0, rst[0]: 6 rst[1] 11

// 57ms 90.38% 90.2MB 100.00%
// DFS
// O(N) O(lgN)
// difficult
class Solution {
    private long[] dfs(List<int[]>[] graph, int u) {
        // without_u, with_u
        long[] rst = new long[2];
        for (int[] v : graph[u]) {
            // without_v, with_v
            long[] sub = dfs(graph, v[0]);
            rst[0] += sub[1];
            rst[1] = Math.max(rst[1], v[1] + sub[0] - sub[1]);
        }
        rst[1] += rst[0];
        System.out.printf("u: %d, rst[0]: %d rst[1] %d\n",
                          u, rst[0], rst[1]);
        return rst;
    }
    public long maxScore(int[][] edges) {
        int n = edges.length;
        List<int[]>[] graph = new List[n];
        for (int u = 0; u < n; ++u) {
            graph[u] = new ArrayList<>();
        }
        int root = 0;
        for (int u = 1; u < n; ++u) {
            graph[edges[u][0]].add(new int[]{u, edges[u][1]});
        }
        long[] rst = dfs(graph, root);
        return Math.max(rst[0], rst[1]);
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
