// Copyright (C) 2020 by iamslash

// 1ms 100.00% 37.2MB 51.64%
// bit manipluation
// O(N^2) O(1)
class Solution {
	public int countTriplets(int[] A) {
		int n = A.length, ans = 0;
		for (int i = 0; i < n; ++i) {
			int bm = A[i];
			for (int k = i+1; k < n; ++k) {
				bm ^= A[k];
				if (bm == 0) {
					ans += k - i;
				}
			}
		}
		return ans;
	}
}
