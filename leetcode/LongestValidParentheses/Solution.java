// Copyright (C) 2020 by iamslash

import java.util.*;

// s: ( ( ) ) )

// 1ms 100.00% 39.3MB 10.98%
// back and forth
// O(N) O(1)
class Solution {
	public int longestValidParentheses(String s) {
		int ans = 0, n = s.length();
		int ext = 0;
		int len = 0;
		for (int i = 0; i < n; ++i) {
			if (s.charAt(i) == '(') {
				ext++;
				len++;
			} else {
				if (ext > 0) {
					ext--;
					len++;
					if (ext == 0) {
						ans = Math.max(ans, len);
					}
				} else {
					ext = 0;
					len = 0;
				}
			}
		}
		len = 0;
		ext = 0;
		for (int i = n-1; i >= 0; --i) {
			if (s.charAt(i) == ')') {
				ext++;
				len++;
			} else {
				if (ext > 0) {
					ext--;
					len++;
					if (ext == 0) {
						ans = Math.max(ans, len);
					}
				} else {
					ext = 0;
					len = 0;
				}
			}
		}
		return ans;
	}
}
