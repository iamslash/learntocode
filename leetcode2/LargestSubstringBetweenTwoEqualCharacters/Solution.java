// Copyright (C) 2020 by iamslash

import java.util.*;

// 0ms 100.00% 36.8MB 20.00%
// hash map
// O(N) O(1)
class Solution {
	public int maxLengthBetweenEqualCharacters(String s) {
		int[] leftMostIdx = new int[26];
		Arrays.fill(leftMostIdx, -1);
		int ans = -1, n = s.length();
		for (int i = 0; i < n; ++i) {
			int j = s.charAt(i) - 'a';
			if (leftMostIdx[j] >= 0) {
				ans = Math.max(ans, i - leftMostIdx[j] - 1);
			} else {
				leftMostIdx[j] = i;
			}
		}
		return ans;
	}
}
