// Copyright (C) 2020 by iamslash

import java.util.*;

// 6ms 13.33% 38.1MB 93.33%
// iterative dynamic programming, sliding window
// O(N) O(K+W)
class Solution {
	public double new21Game(int N, int K, int W) {
		if (K == 0)
			return 1.0;
		double[] probs = new double[K+W];
		Arrays.fill(probs, 0.0);
		probs[0] = 1.0;
		double sum = 1.0;
		for (int i = 1; i < K+W; ++i) {
			probs[i] += sum * (1.0 / W);
			if (i < K)
				sum += probs[i];
			if (i-W >= 0)
				sum -= probs[i-W];
		}
		double ans = 0.0;
		for (int i = K; i < Math.min(N+1, K+W); ++i) {
			ans += probs[i];
		}
		return ans;
	}
}
