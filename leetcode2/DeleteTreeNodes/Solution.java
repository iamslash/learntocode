// Copyright (C) 2020 by iamslash

// 2ms 97.60% 40.2MB 100.00%
// DFS
// O(N) O(N)
class Solution {
	public int deleteTreeNodes(int n, int[] parent, int[] val) {
		// ans[i]: count of remain nodes
		// val[i]: sum of vals including subtree including node i
 		int[] ans = new int[n];
		// traverse from leaves
		for (int i = n - 1; i > 0; --i) {
			val[parent[i]] += val[i];
			ans[parent[i]] += val[i] == 0 ? 0 : ans[i] + 1;
		}
		return val[0] != 0 ? ans[0] + 1 : 0;
	}
}
