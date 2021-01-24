// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 36.7MB 50.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int largestAltitude(int[] gain) {
		int altitude = 0, maxAltitude = 0;
		for (int diff : gain) {
			altitude += diff;
			maxAltitude = Math.max(maxAltitude, altitude);
		}
		return maxAltitude;
	}
}
