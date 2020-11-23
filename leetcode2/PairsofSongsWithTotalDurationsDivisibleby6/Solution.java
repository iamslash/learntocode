// Copyright (C) 2020 by iamslash

// 3ms 80.88% 44.8MB 7.14%
// two sum
// O(N) O(1)
class Solution {
	public int numPairsDivisibleBy60(int[] T) {
		int[] cnts = new int[60];
		int ans = 0;
		for (int t : T) {
			int u = t % 60;
			int v = (60 - u) % 60;
			ans += cnts[v];
			cnts[u]++;
		}
		return ans;
	}
}
