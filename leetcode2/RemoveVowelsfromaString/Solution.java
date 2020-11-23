// Copyright (C) 2020 by iamslash

// 0ms 100.00% 37MB 100.00%
class Solution {
	public String removeVowels(String s) {
		StringBuilder sb = new StringBuilder();
		for (char c : s.toCharArray()) {
			if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u')
				sb.append(c);
		}
		return sb.toString();
	}
}
