// Copyright (C) 2020 by iamslash

//         i
// 0 1 2 3 4
//         j

// 2ms 26.93% 52.6MB 5.56%
// two pointers
// O(N) O(1)
class Solution {
	public boolean validMountainArray(int[] A) {
		int i = 0, j = A.length-1, n = A.length;
		if (n < 3)
			return false;
		while (i < n - 1 && A[i] < A[i+1]) {
			i++;
		}
		while (j > 0 && A[j-1] > A[j]) {
			j--;
		}
		return i > 0  && j < n-1 && i == j;
	}
}
