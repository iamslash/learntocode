// Copyright (C) 2022 by iamslash

import java.util.*;

// DFS from each nodes

// 138ms 70.99% 138.7MB 25.58%
// DFS
// O(N^2) O(N)
class Solution {
    private void dfs(List<List<Integer>> ans, List<List<Integer>> graph,
                     int p, int u) {
        // recursion
        for (int v : graph.get(u)) {
            if (ans.get(v).size() == 0 ||
                ans.get(v).get(ans.get(v).size()-1) != p) {
                ans.get(v).add(p);
                dfs(ans, graph, p, v);
            }
        }                       
    }
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<List<Integer>> ans = new ArrayList<>();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            ans.add(new ArrayList<>());
            graph.add(new ArrayList<>());
        }
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
        }
        for (int u = 0; u < n; ++u) {
            dfs(ans, graph, u, u);
        }
        return ans;
    }
}

public class MainApp {
  public static void main(String[] args) {
  }
}
