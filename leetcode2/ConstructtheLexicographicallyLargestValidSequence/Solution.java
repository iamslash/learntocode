// Copyright (C) 2021 by iamslash

// n: 1
//    1
// n: 2
//    2 1 2
// n: 3
//    3 1 2 3 2
// n: 4
//     
// n: 5
//    5 3 1 4 3 5 2 4 2  

// 0ms 100.00% 36.5MB 77.99%
// back tracking
// O(n!) O(N)
class Solution {
	private boolean dfs(boolean[] visit, int[] ans,
											int pos, int n) {
		// base
		if (pos >= ans.length) {
			return true;
		}		
		// recursion
		if (ans[pos] != 0) {
			return dfs(visit, ans, pos+1, n);
		}		
		for (int i = n; i > 0; --i) {
			if (visit[i]) {
				continue;
			}
			visit[i] = true;
			ans[pos] = i;
			if (i == 1) {
				if (dfs(visit, ans, pos+1, n)) {
					return true;
				}
			} else if (pos + i < ans.length &&
								 ans[pos + i] == 0) {
				ans[pos + i] = i;
				if (dfs(visit, ans, pos+1, n)) {
					return true;
				}
				ans[pos + i] = 0;
			}
			ans[pos] = 0;
			visit[i] = false;
		}
		return false;
	}
	public int[] constructDistancedSequence(int n) {
		int[] ans = new int[2 * n - 1];
		boolean[] visit = new boolean[n+1];
		dfs(visit, ans, 0, n);
		return ans;
	}
}
