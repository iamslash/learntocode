// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// 418ms 14.00% 231.3MB 100.00%
// backtracking
// O(N^2) O(N)
class Solution {
	private void dfs(List<String> abbrs, String word,
									 int pos, String combi, int cnt) {
		// base
		if (pos == word.length()) {
			if (cnt > 0)
				combi += cnt;
			abbrs.add(combi);
			return;					
		}
		// recursion
		dfs(abbrs, word, pos + 1, combi, cnt + 1);
		if (cnt > 0)
			combi += cnt;
		dfs(abbrs, word, pos + 1, combi + word.charAt(pos), 0);		
	}
	private List<String> buildAbbrs(String s) {
			List<String> abbrs = new ArrayList<>();
			dfs(abbrs, s, 0, "", 0);
			return abbrs;
	}
	private boolean match(String abbr, String word) {
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
	public String minAbbreviation(String T, String[] W) {
		List<String> abbrs = buildAbbrs(T);
		Collections.sort(abbrs, (a, b) ->
										 Integer.valueOf(a.length()).compareTo(b.length()));
		for (String abbr : abbrs) {
			boolean bMatch = false;
			for (String word : W) {
				if (match(abbr, word)) {
					bMatch = true;
					break;
				}
			}
			if (bMatch == false) {
				return abbr;
			}
		}
		return "";
	}
}
