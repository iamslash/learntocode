// Copyright (C) 2020 by iamslash

// two pointers
// O(N) O(N)
class Solution {
	public int[] sortedSquares(int[] A) {
		int[] ans = new int[A.length];
        int n = A.length;
		int i = 0, j = n-1, k = n-1;
		while (i <= j) {
			if (Math.abs(A[i]) > Math.abs(A[j])) {
				ans[k] = A[i]*A[i];
                i++;
			} else {
				ans[k] = A[j]*A[j];
                j--;
			}
			k--;
		}
		return ans;
	}
}

