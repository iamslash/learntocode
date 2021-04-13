// Copyright (C) 2021 by iamslash

import java.util.*;

// 35ms 81.67% 47.1MB 53.44%
class Solution {
	private boolean dfs(int[][] G, int[] match, boolean[] visit, int u) {
		int w = G[0].length;
		for (int v = 0; v < w; ++v) {
			if (G[u][v] == 0 || visit[v]) {
				continue;
			}
			visit[v] = true;
			if (match[v] == -1 || dfs(G, match, visit, match[v])) {
				match[v] = u;
				return true;
			}
		}
		return false;
	}
	public int maximumInvitations(int[][] G) {
		int h = G.length;
		int w = G[0].length;
		int[] match = new int[w];
		Arrays.fill(match, -1);
		int ans = 0;
		for (int u = 0; u < h; ++u) {
			boolean[] visit = new boolean[w];
			if (dfs(G, match, visit, u)) {
				ans++;
			}
		}
		for (int v = 0; v < w; ++v) {
			if (match[v] >= 0) {
				System.out.printf("%d -> %d\n", match[v], v);
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
		int[][] G = new int[][]{{1,1,1},{1,0,0},{1,0,0}};
		Solution sln = new Solution();
		System.out.println(sln.maximumInvitations(G));
  }
}
