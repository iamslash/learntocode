// Copyright (C) 2020 by iamslash

import java.util.*;

// 138ms 30.99% 105.5MB 35.57%
class TreeAncestor {

	private Map<Integer, List<Integer>> children = new HashMap<>();
	Integer[][] C;

	private void dfs(int u) {
		for (int i = 1; C[u][i-1] != null; ++i) {
			int p = C[u][i-1];
			C[u][i] = C[p][i-1];
		}
		for (int v : children.getOrDefault(u, new ArrayList<>())) {
			dfs(v);
		}
	}

	public TreeAncestor(int n, int[] parent) {
		C = new Integer[n][30];
		for (int i = 0; i < n; ++i) {
			int u = i;
			int p = parent[i];
			children
					.computeIfAbsent(p, val -> new ArrayList<>())
					.add(u);
			if (i > 0)
				C[u][0] = parent[i];
		}
		dfs(0);
	}
    
	public int getKthAncestor(int u, int k) {
    for (int i = 0; k > 0; ++i) {
			if (k % 2 == 1) {
				if (C[u][i] == null)
					return -1;
				u = C[u][i];
			}
			k >>= 1;
		}
		return u;
	}
}

