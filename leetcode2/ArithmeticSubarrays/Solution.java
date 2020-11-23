// Copyright (C) 2020 by iamslash

import java.util.*;

// 15ms 100.00% 39.8MB 16.67%
// sort
// O(NlgN) O(N)
class Solution {
	private Boolean arithmetic(int[] A, int l, int r) {
		int[] B = Arrays.copyOfRange(A, l, r);
		Arrays.sort(B);
		int diff = B[1] - B[0];
		for (int i = 2; i <= r; ++i) {
			if (B[i] - B[i-1] != diff)
				return false;
		}
		return true;
	}
	public List<Boolean> checkArithmeticSubarrays(int[] A, int[] l, int[] r) {
		int n = l.length;
		List<Boolean> ans = new ArrayList<>();
		for (int i = 0; i < n; ++i) {
			ans.add(arithmetic(A, l[i], r[i]));
		}
		return ans;
	}
}
