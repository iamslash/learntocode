// Copyright (C) 2021 by iamslash

import java.util.*;

//    s: 1 1 1 1
// cnt0: 
// cnt1:

// 4ms 40.00% 39.3MB 20.00%
// brute force
// O(N) O(1)
class Solution {
	public int minOperations(String s) {
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (i % 2 == 0) {
				if (c == '0') {
					cnt0++;
				} else {
					cnt1++;
				}
			} else {
				if (c == '0') {
					cnt1++;
				} else {
					cnt0++;
				}				
			}
		}
		return Math.min(cnt0, cnt1);
	}
}
