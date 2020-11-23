// Copyright (C) 2020 by iamslash
import java.util.Arrays;

// 6ms 99.83% 40.6MB 100.00%
// math
// O(NlgN) O(1)
class Solution {
	public int largestPerimeter(int[] A) {
		Arrays.sort(A);
		for (int i = A.length-2; i >= 0; i--) {
			if (A[i] + A[i+1] > A[i+2])
				return A[i] + A[i+1] + A[i+2];
		}
		return 0;
	}
}
