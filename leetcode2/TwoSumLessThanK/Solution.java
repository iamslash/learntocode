// Copyright (C) 2020 by iamslash

//               i
// A: 1 8 23 24 33 34 54 75
//               j
// K: 60
// S: 58
// ans: 58

// 1ms 100.00% 38.6MB 33.33%
// sort
// O(NlgN) O(1)
class Solution {
	public int twoSumLessThanK(int[] A, int K) {
		Arrays.sort(A);
		int i = 0, j = A.length - 1;
		int ans = -1;
		while (i < j) {
			S = A[i] + A[j];
			if (S < K) {
 				++i;
				if (ans < S)
					ans = S;
			} else {
				--j;
			}
		}
		return ans;
	}
}
