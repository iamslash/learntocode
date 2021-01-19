// Copyright (C) 2021 by iamslash

import java.util.*;

// 277ms 51.25% 59.5MB 50.00%
// disjoint set
// query: O(nlgn) O(nlgn)
class DistanceLimitedPathsExist {
	// {distance, parent[]}
	TreeMap<Integer, int[]> distMap = new TreeMap<>();
	
	public DistanceLimitedPathsExist(int n, int[][] E) {
		Queue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
		Arrays.stream(E).forEach(e -> pq.add(e));
		int[] parent = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}
		while (pq.size() > 0) {
			int[] top = pq.poll();
			int u = top[0];
			int v = top[1];
			int d = top[2];
			merge(parent, u, v);
			distMap.put(d, parent.clone());
		}
	}
    
	public boolean query(int p, int q, int limit) {
		Integer lower = distMap.lowerKey(limit);
		if (lower == null) {
			return false;
		}
		int[] parent = distMap.get(lower);
		return find(parent, p) == find(parent, q);
	}
	private int find(int[] parent, int u) {
		if (parent[u] == u) {
			return u;
		}
		return parent[u] = find(parent, parent[u]);
	}
	private void merge(int[] parent, int u, int v) {
		u = find(parent, u);
		v = find(parent, v);
		parent[v] = u;
	}
}
