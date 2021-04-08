// Copyright (C) 2021 by iamslash

import java.util.*;

class Solution {
	private boolean dfs(int u, int[][] G, int[] match, boolean[] visit) {
		int w = G[0].length;
		for (int v = 0; v < w; ++v) {
			if (G[u][v] == 0 || visit[v]) {
				continue;
			}
			visit[v] = true;
			if (match[v] == -1 || dfs(match[v], G, match, visit)) {
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
		for (int i = 0; i < h; ++i) {
			boolean[] visit = new boolean[w];
			if (dfs(i, G, match, visit)) {
				ans++;
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
