// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 93.49% 37.3MB 68.38%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int numDecodings(String s) {
		if (s.isEmpty() || s.charAt(0) == '0')
			return 0;
		int n1 = 1, n2 = 0;
		for (int i = 1; i < s.length(); i++) {
			int m1 = 0, m2 = 0;
			char c = s.charAt(i);
			if (c >= '1' && c <= '9') {
				m1 = n1 + n2;
			}
			int n = Integer.parseInt(s.substring(i-1, i+1));
			if (n >= 10 && n <= 26) {
				m2 = n1;
			}
			n1 = m1;
			n2 = m2;
		}
		return n1 + n2;
	}
}
