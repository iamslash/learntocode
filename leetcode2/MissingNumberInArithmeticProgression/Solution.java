// Copyright (C) 2020 by iamslash

//    i
// A: 5 7 11 13

//    i
// A: 5 7 8

//    i
// A: 5 6 8
// 7

// 0ms 100.00% 39.3MB 100.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int missingNumber(int[] A) {
		int n = A.length;
		int sum = 0; 
		for (int i = 0; i < n-1; ++i) {
			sum += A[i+1] - A[i];
		}
		int diff = sum / n;
		for (int i = 0; i < n-1; ++i) {
			if (A[i] + diff != A[i+1])
				return A[i] + diff;
		}
		return A[n-1];
	}
}
