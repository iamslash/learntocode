// Copyright (C) 2021 by iamslash

//  n: 10
//                        i
//  C: 1 2 3 4 5 6 8 9 10 0
// i2: 5
// i3: 3
// i5: 2


// 4ms 56.19% 39.1MB 10.00%
// iterative dynamic programming
// O(N) O(N)
class Solution {
	public int nthUglyNumber(int n) {
		int[] C = new int[n];
		C[0] = 1;
		// index to be multiplied by 2, 3, 5
		int i2 = 0, i3 = 0, i5 = 0;
		for (int i = 1; i < n; ++i) {
			int num = Math.min(C[i2]*2, Math.min(C[i3]*3, C[i5]*5));
			if (num == C[i2]*2) {
				i2++;
			}
			if (num == C[i3]*3) {
				i3++;
			}
			if (num == C[i5]*5) {
				i5++;
			}
			C[i] = num;
		}
		return C[n-1];
	}
}
