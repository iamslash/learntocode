// Copyright (C) 2020 by iamslash

// 6ms 89.14% 39.7MB 50.00%
// brute force
// O(HW) O(1)
class Solution {
	public int minDeletionSize(String[] A) {
		int m = A.length, n = A[0].length(), decCnt = 0;
		for (int j = 0; j < n; j++) {
			for (int i = 1; i < m; i++) {
				if (A[i-1].charAt(j) > A[i].charAt(j)) {
					decCnt++;
					break;
				}
			}
		}
		return decCnt;
	}
}

