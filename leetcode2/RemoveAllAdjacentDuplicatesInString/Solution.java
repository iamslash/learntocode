// Copyright (C) 2020 by iamslash

import java.util.Deque;
import java.util.ArrayDeque;

//     s: a b b a c a
//                i
// deque: c  

// 7ms 84.52% 40.5MB 100.00%
// stack
// O(N) O(N)
class Solution {
	public String removeDuplicates(String s) {
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (sb.length() > 0 && sb.charAt(sb.length()-1) == c) {
				sb.deleteCharAt(sb.length()-1);
			} else {
				sb.append(c);
			}
		}
		return sb.toString();
	}
}
