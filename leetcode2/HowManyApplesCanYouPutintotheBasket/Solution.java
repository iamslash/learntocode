// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 97.15% 39.3MB 100.00%
// sort
// O(NlgN) O(1)
class Solution {
	public int maxNumberOfApples(int[] A) {
		Arrays.sort(A);
		int sum = 0;
		for (int i = 0; i < A.length; ++i) {
			if (sum + A[i] > 5000)
				return i;
			sum += A[i];
		}
		return A.length;
	}
}
