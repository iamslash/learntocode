// Copyright (C) 2020 by iamslash

// K: 2
//          i
// C: 0 1 2 3 4 

// 1ms 100.00% 46.7MB 100.00%
// partial sum
// O(N) O(N)
class Solution {
	public int dietPlanPerformance(int[] C, int K, int L, int U) {
		int n = C.length;
		int[] ps = new int[n+1];
		for (int i = 0; i < n; ++i)
			ps[i+1] = ps[i] + C[i];
		int ans = 0;
		for (int i = 0; i+K-1 < n; ++i) {
			int sum = ps[i+K] - ps[i];
			if (sum < L)
				ans--;
			else if (sum > U)
				ans++;
		}
		return ans;
	}
}
