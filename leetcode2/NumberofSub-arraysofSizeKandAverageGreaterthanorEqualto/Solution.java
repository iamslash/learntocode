// Copyright (C) 2020 by iamslash

// K: 3, T: 4
// A: 2 2 2 2 5 5 5 8
//            i
// 

// 3ms 55.83% 52MB 100.00%
// partial sum
// O(N) O(N)
class Solution {
	public int numOfSubarrays(int[] A, int K, int T) {
		int[] ps = new int[A.length+1];
		for (int i = 0; i < A.length; ++i)
			ps[i+1] = ps[i] + A[i];
		int ans = 0;
		for (int i = 0; i <= A.length - K; ++i) {
			if ((ps[i+K] - ps[i]) / K >= T)
				ans++;
		}
		return ans;
	}
}
