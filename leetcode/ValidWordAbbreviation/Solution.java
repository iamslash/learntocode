// Copyright (C) 2020 by iamslash

// 1ms 90.32% 37.9MB 12.50%
// linear traversal
// O(N) O(1)
class Solution {
	public boolean validWordAbbreviation(String word, String abbr) {
		if (word == null || abbr == null)
			return false;
		int num = 0, pos = 0;
		for (char c : abbr.toCharArray()) {
			if (c == '0' && num == 0)
				return false;
			if (c >= '0' && c <= '9') {
				num = num * 10 + (c - '0');
			} else {
				pos += num;
				if (pos >= word.length() ||
						c != word.charAt(pos))
					return false;
				num = 0;
				pos++;
			}
		}
		return pos + num == word.length() ? true : false;
	}
}
