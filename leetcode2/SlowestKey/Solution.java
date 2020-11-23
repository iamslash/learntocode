// Copyright (C) 2020 by iamslash

// 0ms 100.00% 38.8MB 25.00%
// linear traveral
// O(N) O(1)
class Solution {
	public char slowestKey(int[] releaseTimes,
												 String keysPressed) {
		int maxDiff = releaseTimes[0], maxIdx = 0, n = releaseTimes.length;
		for (int i = 1; i < n; ++i) {
			if (maxDiff <= releaseTimes[i] - releaseTimes[i-1]) {
				maxDiff = releaseTimes[i] - releaseTimes[i-1];
				maxIdx = i;
			}
		}
		return keysPressed.charAt(maxIdx);
	}
}
