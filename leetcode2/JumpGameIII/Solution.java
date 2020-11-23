// Copyright (C) 2020 by iamslash

// 0ms 100.00% 47.5MB 100.00%
// DFS
// O(2^N) O(N)
class Solution {
	private boolean dfs(int[] A, int[] C, int pos) {
		// base
		if (pos < 0 || pos >= A.length)
			return false;
		if (C[pos] > 0)
			return false;
		if (A[pos] == 0)
			return true;
		C[pos] = 1;
		// recursion
		return dfs(A, C, pos-A[pos]) || dfs(A, C, pos + A[pos]);
	}
	public boolean canReach(int[] A, int S) {
		int[] C = new int[A.length];
		return dfs(A, C, S-A[S]) || dfs(A, C, S + A[S]);
	}
}
