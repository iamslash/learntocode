// Copyright (C) 2020 by iamslash

import java.util.*;

// 6ms 85.41% 47.7MB 5.09%
// dynamic programming, sliding window
// O(N) O(N)
class Solution {
	public int minSumOfLengths(int[] A, int target) {
		int n = A.length, l = 0, r = 0, sum = 0, ans = Integer.MAX_VALUE;
		int[] C = new int[n];
		Arrays.fill(C, Integer.MAX_VALUE);
		for (r = 0; r < n; ++r) {
			sum += A[r];
			// Forward l
			while (sum > target) {
				sum -= A[l++];
			}
			// Update ans
			if (sum == target) {
				C[r] = r - l + 1;
				if (l > 0 && C[l-1] != Integer.MAX_VALUE) {
					ans = Math.min(ans, C[l-1] + C[r]);
				}
			}
			// Update C[r]
			if (r > 0) {
				C[r] = Math.min(C[r], C[r-1]);
			}		 
		}
		if (ans == Integer.MAX_VALUE)
			return -1;
		return ans;
	}
}
