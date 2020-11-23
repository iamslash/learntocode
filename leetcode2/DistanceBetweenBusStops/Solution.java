// Copyright (C) 2020 by iamslash

// 0ms 100.00% 39.7MB 100.00%
// brute force
// O(N) O(1)
class Solution {
	public int distanceBetweenBusStops(int[] D, int s, int d) {
		int tol = 0, tor = 0, p = s, n = D.length;
		while (p != d) {
			tol += D[p];
			p = (p + 1) % n;
		}
		while (p != s) {
			tor += D[p];
			p = (p + 1) % n;			
		}
		return Math.min(tol, tor);
	}
}
