// Copyright (C) 2020 by iamslash

// 1: 0001
// 3: 0011
// 4: 0100
// 8: 1000

// 1ms 100.00% 50.1MB 100.00%
// partial sum
// O(N) O(N)
class Solution {
	public int[] xorQueries(int[] A, int[][] Q) {
		int n = A.length;
		int[] ps = new int[n+1];
		for (int i = 0; i < n; ++i) {
			ps[i+1] = ps[i] ^ A[i];
		}
		int[] ans = new int[Q.length];
		for (int i = 0; i < Q.length; ++i) {			
			ans[i] = ps[Q[i][1]+1] ^ ps[Q[i][0]];
		}
		return ans;
	}
}
