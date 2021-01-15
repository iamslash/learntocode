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

class Solution {
	private int[] best;
	private int[] comb;
	private bool dfs(int n, int i) {
		// base
		if (i >= n) {
			best = comb;
			return true;
		}
		// recursion
		if (i == 0) {			
			return dfs(n, i+1);
		}
		return false;
	}
	public int[] constructDistancedSequence(int n) {
		best = new int[n];
		comb = new int[n];
		dfs(n, 0);
		return best;
	}
}
