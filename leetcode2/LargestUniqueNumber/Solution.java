// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 81.45% 39.1MB 33.33%
// sort
// O(NlgN) O(1)
class Solution {
	public int largestUniqueNumber(int[] A) {
		Arrays.sort(A);
		int n = A.length;
		for (int i = n-1; i >= 0; --i) {
			int l = i > 0 ? A[i-1] : -1;
			int m = A[i];
			int h = i < n-1 ? A[i+1] : -1;
			if (l != m && m != h)
				return m;
		}		
		return -1;
	}
}
