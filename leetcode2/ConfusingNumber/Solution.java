// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36.2MB 50.00%
// hash
// O(N) O(1)
class Solution {
	public boolean confusingNumber(int N) {
		int[] rotate = {0, 1, -2, -3, -4, -5, 9, -7, 8, 6};
		int M = N;
		int rotatedN = 0;
		while (N > 0) {
			int d = N % 10;
			if (rotate[d] < 0)
				return false;
			rotatedN = rotatedN * 10 + rotate[d];
			N /= 10;
		}
		return M != rotatedN;
	}
}
