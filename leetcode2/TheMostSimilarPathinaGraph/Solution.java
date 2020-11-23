// Copyright (C) 2020 by iamslash

import java.util.*;

// // 214ms 27.19% 107.1MB 8.77%
// class Solution {
// 	private int dfs(List<List<Integer>> G, int[][] visit, int[][] next,
// 									String[] names, String[] paths, int nameIdx, int pathIdx) {
// 		if (visit[nameIdx][pathIdx] != -1)
// 			return visit[nameIdx][pathIdx];
// 		int editDist = 1;
// 		if (names[nameIdx].equals(paths[pathIdx]))
// 			editDist = 0;
// 		if (pathIdx == paths.length - 1)
// 			return editDist;
// 		int minCost = Integer.MAX_VALUE;
// 		for (int v : G.get(nameIdx)) {
// 			int vCost = dfs(G, visit, next, names, paths, v, pathIdx+1);
// 			if (vCost < minCost) {
// 				minCost = vCost;
// 				next[nameIdx][pathIdx] = v;
// 			}
// 		}
// 		editDist += minCost;
// 		visit[nameIdx][pathIdx] = editDist;
// 		return editDist;
// 	}
// 	public List<Integer> mostSimilar(int n, int[][] roads, String[] names, String[] paths) {
// 		List<List<Integer>> G = new ArrayList<>();
// 		int[][] visit = new int[names.length][paths.length];
// 		int[][] next  = new int[names.length][paths.length];
// 		for (int[] x : visit) {
// 			Arrays.fill(x, -1);
// 		}
// 		for (int i = 0; i < n; ++i) {
// 			G.add(new ArrayList<>());
// 		}
// 		for (int[] e : roads) {
// 			int u = e[0], v = e[1];
// 			G.get(u).add(v);
// 			G.get(v).add(u);
// 		}
// 		int minCost = Integer.MAX_VALUE;
// 		int beg = 0;
// 		for (int u = 0; u < names.length; ++u) {
// 			int cost = dfs(G, visit, next, names, paths, u, 0);
// 			if (cost < minCost) {
// 				minCost = cost;
// 				beg = u;
// 			}
// 		}
// 		List<Integer> ans = new ArrayList<>();
// 		while (ans.size() < paths.length) {
// 			ans.add(beg);
// 			beg = next[beg][ans.size()-1];
// 		}
// 		return ans;
// 	}
// }

// 197ms 28.07% 109.7MB 5.26%
class Solution {
	public List<Integer> mostSimilar(int n, int[][] roads, String[] names, String[] targetPath) {
		// build the graph
		List<Integer>[] G	= new ArrayList[n];
		for(int[] r: roads) {
			int u	= r[0]; int v = r[1];
			if (G[u] == null)
				G[u] = new ArrayList<>();
			if (G[v] == null)
				G[v] = new ArrayList<>();
			G[u].add(v);
			G[v].add(u);
		}
    
		int	m	= targetPath.length;
		int[][] path = new int[n][m];	// record the path. path[i][j] stores the previous city 
		// for city i at position j
		int[][] dist = new int[n][m];	// dist[i][j] is the min edit distance for city i at position j
		PriorityQueue<int[]> pq	= new PriorityQueue<>((a, b)->{
				int da = dist[a[0]][a[1]];
				int db = dist[b[0]][b[1]];
				return da - db;
		});
		
		for(int i = 0; i < n; i++) {
			dist[i][0] = targetPath[0].equals(names[i]) ? 0 : 1;
			pq.offer(new int[]{i, 0});
			for(int j	 = 1; j < m; j++)
				dist[i][j] = Integer.MAX_VALUE;
		}
    
		int	minCost	= Integer.MAX_VALUE;
		while(!pq.isEmpty()) {
			int[] a	= pq.poll();
			int	c	= a[0];
			int p	= a[1];
			int	d	= dist[c][p];
			if (p	== m-1)
				break;
			for(int b: G[a[0]]) {
				int dd = d + (targetPath[p+1].equals(names[b]) ? 0 : 1);
				if (dd < dist[b][p+1]) {
					dist[b][p+1] = dd;
					pq.offer(new int[]{b, p+1});
					path[b][p+1] = c;
				}
			}
		}
    
		int last = 0;
		for(int i = 1; i < n; i++) {
			if (dist[i][m-1] < dist[last][m-1])
				last = i;
		}
    
		LinkedList<Integer> ans	= new LinkedList<>();
		for(int i	= m-1; i >= 0; i--) {
			ans.push(last);
			last = path[last][i];
		}
		return ans;
	}
}
