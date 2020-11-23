// Copyright (C) 2020 by iamslash

import java.util.*;

// 3ms 62.47% 37MB 75.96%
// two pointers
// O(ST) O(1)
class Solution {
	public int shortestWay(String s, String t) {
		int i = 0, j = 0, ans = 0;
		while (j < t.length() && ans <= j) {
			if (i < s.length()) {
				if (s.charAt(i) == t.charAt(j)) {
					i++;
					j++;
				} else {
					i++;
				}
			} else {
				i = 0;
				ans++;
			}			 
		}
		if (++ans > j)
			return -1;
		return ans;
	}
}
