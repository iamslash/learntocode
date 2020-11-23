// Copyright (C) 2020 by iamslash

import java.util.Set;
import java.util.HashSet;
import java.util.Arrays;

// 5ms 68.01% 59.2MB 100.005
// disjoint set
// O(N) O(N)
class Solution {
	private Integer[] parents;
	private int find(int u) {
		if (parents[u] == u)
			return u;
		return parents[u] = find(parents[u]);
	}
	private boolean merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v)
			return false;
		parents[u] = v;
		return true;
	}
	public int makeConnected(int n, int[][] cons) {
		int extra = 0;
		parents = new Integer[n];
		for (int i = 0; i < n; ++i)
			parents[i] = i;
		for (int[] c : cons) {
			if (!merge(c[0], c[1]))
				extra++;
		}
		int cluster = 0;
		for (int i = 0; i < n; ++i)
			if (i == parents[i])
				cluster++;
		if (extra < cluster - 1)
			return -1;
		return cluster - 1;
	}
}
