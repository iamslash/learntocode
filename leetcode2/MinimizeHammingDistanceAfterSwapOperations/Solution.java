// Copyright (C) 2021 by iamslash

import java.util.*;

// s: 5 1 2 4 3
// t: 1 5 4 2 3
// a: 0,4 4,2 1,3 1,4

// 43ms 98.84% 79.5MB 86.27%
// disjoint set, union find, merge find
// O(N) O(N)
class DisjointSet {
	private int[] parent;
	public DisjointSet(int n) {
		parent = new int[n];
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}		
	}
	public void merge(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		parent[u] = v;
	}
	public int find(int u) {
		if (parent[u] == u) {
			return u;
		}
		return parent[u] = find(parent[u]);
	}
}
class Solution {
	public int minimumHammingDistance(int[] src, int[] tgt, int[][] allowedSwaps) {
		int minHam = 0;
		int n = src.length;
		DisjointSet ds = new DisjointSet(n);
		for (int[] idxs : allowedSwaps) {
			ds.merge(idxs[0], idxs[1]);
		}
		Map<Integer, Map<Integer, Integer>> numMap = new HashMap<>();
		for (int i = 0; i < n; ++i) {
			int num = src[i];
			int root = ds.find(i);
			numMap.putIfAbsent(root, new HashMap<>());
			// {root : {num : cnt}}
			Map<Integer, Integer> childMap = numMap.get(root);
			childMap.put(num, childMap.getOrDefault(num, 0) + 1);			
		}
		for (int i = 0; i < n; ++i) {
			int num = tgt[i];
			int root = ds.find(i);
			Map<Integer, Integer> childMap = numMap.get(root);
			if (childMap.getOrDefault(num, 0) == 0) {
				minHam++;
			} else {
				childMap.put(num, childMap.get(num) - 1);
			}
		}
		return minHam;
	}
}
