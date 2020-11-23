// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;

// TO BE OR NOT TO BE
//
// TBONTB
// OEROOE
//    T

// 1ms 73.57% 37.5MB 100.00%
// rotate array
// O(HW) O(HW)
class Solution {
	public List<String> printVertically(String s) {
		String[] words = s.split(" ");
		int h = 0;
		for (String w : words) {
			h = Math.max(h, w.length());
		}
		List<String> ans = new ArrayList<>();
		for (int i = 0; i < h; ++i) {
			StringBuffer sb = new StringBuffer();
			for (String w : words) {
				char c = ' ';
				if (i < w.length())
					c = w.charAt(i);
				sb.append(c);
			}
			while (sb.charAt(sb.length()-1) == ' ')
				sb.deleteCharAt(sb.length()-1);
			ans.add(sb.toString());
		}
		return ans;
	}
}
