
import java.util.*;

// 96ms 74.16% 147MB 59.00%
// DFS
// O(N) O(N)
class Solution {
    private long ans = 0;
    private int seats = 0;
    private long dfs(List<List<Integer>> graph, int u, int p) {
        // base
        int people = 1;
        // recursion
        for (int v : graph.get(u)) {
            if (v == p) {
                continue;
            }
            people += dfs(graph, v, u);
        }
        if (u != 0) {
            long ceiling = (people + seats - 1) / seats;
            ans += ceiling;
        }
        return people;
    }
    public long minimumFuelCost(int[][] roads, int seats) {
        List<List<Integer>> graph = new ArrayList<>();
        this.seats = seats;
        int n = roads.length;
        for (int i = 0; i <= n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int i = 0; i < n; ++i) {
            int u = roads[i][0], v = roads[i][1];
            graph.get(u).add(v);
            graph.get(v).add(u);
        }
        dfs(graph, 0, 0);
        return ans;
    }
}
