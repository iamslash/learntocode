// 97ms 78.43% 111.4MB 69.68%
// DFS
// O(V+E) O(V)
class Solution {
    private int seq = 0;
    private List<Integer> order;
    private List<List<Integer>> ans;
    private List<List<Integer>> G;
    private int dfs(int u, int p) {
        // base
        order.set(u, seq++);
        int minOrder = order.get(u);
        // recursion
        for (int v : G.get(u)) {
            if (v == p) {
                continue;
            }
            if (order.get(v) == -1) {
                int inMinOrder = dfs(v, u);
                if (inMinOrder > order.get(u)) {
                    ans.add(Arrays.asList(u, v));
                }
                minOrder = Math.min(minOrder, inMinOrder);
            } else {
                minOrder = Math.min(minOrder, order.get(v));
            }
        }
        return minOrder;
    }
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        ans = new ArrayList<>();
        order = new ArrayList<>();
        G = new ArrayList<>();        
        for (int u = 0; u < n; ++u) {
            G.add(new ArrayList<>());
            order.add(-1);
        }
        // Build graph
        for (List<Integer> conn : connections) {
            int u = conn.get(0), v = conn.get(1);
            G.get(u).add(v);
            G.get(v).add(u);
        }
        dfs(0, 0);
        return ans;
    }
}
