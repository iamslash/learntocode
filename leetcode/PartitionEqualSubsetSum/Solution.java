// Copyright (C) 2020 by iamslash

//        i
// A: 5 2 1
// C: t t t t f 
//      a
//
// A: 5 4 1
//
//        i
// A: 3 3 3 4 5
// C: t f f t f f t f f t
//                      a

// 21ms 59.90% 38.8MB 5.07%
// iterative dynamic programming
// O(HN) O(H)
class Solution {
	public boolean canPartition(int[] A) {
		int half = 0;
		for (int a : A) {
			half += a;
		}
		if (half % 2 == 1) {
			return false;
		}
		half /= 2;
		boolean[] C = new boolean[half+1];
		C[0] = true;
		for (int i = 0; i < A.length; ++i) {
			for (int amount = half; amount > 0; --amount) {
				if (amount >= A[i]) {
					C[amount] = C[amount] || C[amount - A[i]];
				}
			}
		}
		return C[half];
	}
}
