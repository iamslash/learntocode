// Copyright (C) 2020 by iamslash

// 2 3 1 4 2 2

// 0ms 100.00% 40.5MB 76.54%
// linear traversal
// O(N) O(1)
class Solution {
	public int repeatedNTimes(int[] A) {
		for (int i = 0; i < A.length-2; ++i) {
			if (A[i] == A[i+1] || A[i] == A[i+2])
				return A[i];
		}
		return A[A.lenght-1];
	}
}
