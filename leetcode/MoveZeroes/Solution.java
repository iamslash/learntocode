// Copyright (C) 2020 by iamslash

// 0ms 100.00% 42.1MB 9.54%
// two pointers
// O(N) O(1)
class Solution {
	public void moveZeroes(int[] A) {
		int i = 0, j = 0, n = A.length;
		while (j < n) {
			if (A[j] != 0) {
				A[i] = A[j];
				++i;
			}
			++j;
		}
		for (int k = i; k < n; ++k) {
			A[k] = 0;
		}
	}
}
