// Copyright (C) 2020 by iamslash

// 4ms 97.57% 47.5MB 100.00%
// array
// O(N) O(N)
class Solution {
	public int[] sumEvenAfterQueries(int[] A, int[][] Q) {
		int sum = 0, i = 0;
		for (int a : A) {
			if (a % 2 == 0)
				sum += a;
		}
		int[] ans = new int[A.length];
		for (int[] q : Q) {
			if (A[q[1]] % 2 == 0) {
				sum -= A[q[1]];
			}
			A[q[1]] += q[0];
			if (A[q[1]] % 2 == 0) {
				sum += A[q[1]];
			}
			ans[i++] = sum;
		}
		return ans;
	}
}
