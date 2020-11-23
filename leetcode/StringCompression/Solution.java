// Copyright (C) 2020 by iamslash

import java.util.*;

// 1ms 94.35% 38.8MB 8.53%
// linear traversal
// O(N) O(1)
class Solution {
	public int compress(char[] chars) {
		int i = 0, j = 0, n = chars.length;
		while (j < n) {
			char c = chars[j];
			int cnt = 0;
			while (j < n && chars[j] == c) {
				j++;
				cnt++;
			}
			chars[i] = c;
			i++;
			if (cnt > 1) {
				String s = Integer.toString(cnt);
				for (char d : s.toCharArray()) {
					chars[i++] = d;
				}
			}
		}
		return i;
	}
}
