// Copyright (C) 2020 by iamslash

import java.util.*;

// 13ms 14.29% 51.3MB 28.57%
// greedy algorithm
// O(N) O(1)
class Solution {
	public int minPartitions(String s) {
		int ans = 0;
		for (int i = 0; i < s.length(); ++i) {
			ans = Math.max(ans, s.charAt(i)-'0');
		}
		return ans;
	}
}

// 5ms 71.43% 39.2MB 100.00%
// greedy algorithm
// O(N) O(1)
class Solution {
	public int minPartitions(String s) {
		int ans = 0;
		for (char c : s.toCharArray()) {
			ans = Math.max(ans, c-'0');
		}
		return ans;
	}
}

