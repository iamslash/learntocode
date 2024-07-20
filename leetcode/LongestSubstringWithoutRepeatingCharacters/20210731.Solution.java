// Copyright (C) 2020 by iamslash

import java.util.*;

//         i
//    s: a b c a b c b b
//             j
// cnts: a b c
//       1 1 1
//  ans: 0

// 2ms 99.82% 38.8MB 91.94%
// two pointers
// O(N) O(1)
class Solution {
	public int lengthOfLongestSubstring(String s) {
		int i = 0, j = 0, ans = 0, n = s.length();
		int[] cnts = new int[256];
		for (j = 0; j < n; ++j) {
			// increment cnt of s[j]
			cnts[s.charAt(j)]++;
			// foward i
			while (i < j && cnts[s.charAt(j)] > 1) {
				cnts[s.charAt(i)] = Math.max(0, --cnts[s.charAt(i)]);
				i++;
			}
			ans = Math.max(ans, j-i+1);
 			// foward j
		}
		return ans;
	}
}
