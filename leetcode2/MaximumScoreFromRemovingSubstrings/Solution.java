// Copyright (C) 2021 by iamslash

import java.util.*;

// x: 4
// y: 5
// cdbcbbaaabab   5
// cdbcbaabab     5
// cdbcabab       5
// cdbcab         4
// cdbc

// 62ms 77.89% 41.9% 57.19%
// stack
// O(N) O(N)
class Solution {
	public int maximumGain(String s, int x, int y) {
		int ans = 0;
		String z = "ab", w = "ba";
		if (x < y) {
			int t = x;
			x = y;
			y = t;
			z = "ba";
			w = "ab";
		}
		Deque<Character> xStack = new ArrayDeque<>();
		for (char c : s.toCharArray()) {
			if (!xStack.isEmpty() &&
					xStack.getLast() == z.charAt(0) &&
					c == z.charAt(1)) {
				xStack.pollLast();
				ans += x;
			} else {
				xStack.addLast(c);
			}
		}
		Deque<Character> yStack = new ArrayDeque<>();
		while (!xStack.isEmpty()) {
			char c = xStack.pollLast();
			if (!yStack.isEmpty() &&
					yStack.getLast() == w.charAt(1) &&
					c == w.charAt(0)) {
				yStack.pollLast();
				ans += y;
			} else {
				yStack.addLast(c);
			}
		}		
		return ans;		
	}
}
