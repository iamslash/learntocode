import java.util.*;

// 9ms 81.46% 46MB 100.00%
// DFS
// O(V+E) O(V)
class Solution {
  private boolean dfs(List<List<Integer>> G,
                      List<Integer> D,
                      List<Integer> S,
                      int u) {
    // base
    if (S.get(u) == 1)
      return true;
    if (S.get(u) == 0)
      return false;
    // recursion
    S.set(u, 0);
    for (Integer v : G.get(u)) {
      if (!dfs(G, D, S, v))
        return false;
      D.set(u, Math.max(D.get(u), 1 + D.get(v)));
    }
    S.set(u, 1);
    return true;
  }
  public int minimumSemesters(int N, int[][] R) {
    List<List<Integer>> G = new ArrayList<>();
    for (int i = 0; i < N; ++i)
      G.add(new ArrayList<Integer>());
    List<Integer> D = new ArrayList<Integer>(Collections.nCopies(N,  1));
    List<Integer> S = new ArrayList<Integer>(Collections.nCopies(N, -1));
    for (int[] e : R) {
      int u = e[0]-1;
      int v = e[1]-1;
      G.get(u).add(v);
    }
    // for (List<Integer> g : G)
    //   System.out.println(Arrays.toString(g.toArray()));
    
    for (int u = 0; u < N; ++u) {
      if (!dfs(G, D, S, u))
        return -1;
    }
    return Collections.max(D);
  }
  public static void main(String[] args) {
    int N = 3;
    int[][] R = {{1, 3},{2, 3}};
    Solution sln = new Solution();
    System.out.println(String.format("%d", sln.minimumSemesters(N, R)));    
  }
}
