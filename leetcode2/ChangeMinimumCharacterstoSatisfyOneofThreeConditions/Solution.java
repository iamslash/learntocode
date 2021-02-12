// Copyright (C) 2021 by iamslash

import java.util.*;

// a: a b a
// b: c a a
//
// aFreq: a b
//        2 1
// bFreq: a c
//        2 1

// 11ms 72.82% 39.6MB 74.40%
// brute force
// O(N) O(1)
class Solution {
	public int minCharacters(String a, String b) {
		int m = a.length(), n = b.length(), ans = m + n;
		int[] aFreq = new int[26], bFreq = new int[26];
		for (int i = 0; i < m; ++i) {
			aFreq[a.charAt(i)-'a']++;
		}
		for (int i = 0; i < n; ++i) {
			bFreq[b.charAt(i)-'a']++;
		}
		for (int i = 0; i < 26; ++i) {
			// cond 3
			ans = Math.min(ans, m - aFreq[i] + n - bFreq[i]);
			if (i > 0) {
				aFreq[i] += aFreq[i-1];
				bFreq[i] += bFreq[i-1];
			}
			if (i < 25) {
				// cond 1
				ans = Math.min(ans, m - aFreq[i] + bFreq[i]); 
				// cond 2
				ans = Math.min(ans, n - bFreq[i] - aFreq[i]); 
			}
		}
		return ans;
	}
}
