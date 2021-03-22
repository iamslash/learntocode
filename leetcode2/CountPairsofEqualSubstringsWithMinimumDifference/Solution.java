// Copyright (C) 2021 by iamslash

import java.util.*;

// abc
//  bccdab

// 8ms 100.00% 40.8MB 100.00%
// brute force
// O(N) O(1)
class Solution {
	public int countQuadruples(String s1, String s2) {
		int min = Integer.MAX_VALUE;
		int cnt = 0;
		for (char c = 'a'; c <= 'z'; ++c) {
			int j = s1.indexOf(c);
			int a = s2.lastIndexOf(c);
			if (j == -1 || a == -1) {
				continue;
			}
			if (j - a < min) {
				min = j - a;
				cnt = 0;
			}
			if (j - a == min) {
				cnt++;
			}															 
		}
		return cnt;
	}
}
