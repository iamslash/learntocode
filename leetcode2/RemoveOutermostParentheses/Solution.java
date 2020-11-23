// Copyright (C) 2020 by iamslash

// 3ms 6367% 39.2MB 5.19%
// string
// O(N) O(N)
class Solution {
	public String removeOuterParentheses(String S) {
		StringBuilder sb = new StringBuilder();
		int stat = 0;
		for (int i = 0; i < S.length(); ++i) {
			char c = S.charAt(i);
			if (c == '(') {
				if (stat > 0)
					sb.append(c);
				stat++;
			} else {
				stat--;
				if (stat > 0)
					sb.append(c);
			}
		}
		return sb.toString();
	}
}
