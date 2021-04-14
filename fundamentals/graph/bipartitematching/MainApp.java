// Copyright (C) 2021 by iamslash

import java.util.*;

class Solution {
	private void dump(int step, int[] match, boolean[] visit, int u) {
		for (int i = 0; i < step; ++i) {
			System.out.printf(" ");
		}
		System.out.printf("match: [");
		for (int i = 0; i < match.length; ++i) {
			System.out.printf("%d,", match[i]);
		}
		System.out.printf("], ");
		System.out.printf("visit: [");
		for (int i = 0; i < visit.length; ++i) {
			System.out.printf("%s,", visit[i] ? "t" : "f");
		}
		System.out.printf("], u: %d\n", u);
	}
	private boolean dfs(int step, int[][] G, int[] match, boolean[] visit, int u) {
		dump(step, match, visit, u);
		int w = G[0].length;
		for (int v = 0; v < w; ++v) {
			if (G[u][v] == 0 || visit[v]) {
				continue;
			}
			visit[v] = true;
			if (match[v] == -1 || dfs(step+1, G, match, visit, match[v])) {
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
			if (dfs(0, G, match, visit, u)) {
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
