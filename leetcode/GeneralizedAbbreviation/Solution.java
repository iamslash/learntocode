// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;

// 12ms 54.02% 45% 100.00%
// backtracking
// O(N^2) O(N)
class Solution {
	private void dfs(List<String> ans, String word,
									 int pos, String combi, int cnt) {
		// base
		if (pos == word.length()) {
			if (cnt > 0)
				combi += cnt;
			ans.add(combi);
			return;					
		}
		// recursion
		dfs(ans, word, pos + 1, combi, cnt + 1);
		if (cnt > 0)
			combi += cnt;
		dfs(ans, word, pos + 1, combi + word.charAt(pos), 0);
	}
	public List<String> generateAbbreviations(String word) {
		List<String> ans = new ArrayList<>();
		dfs(ans, word, 0, "", 0);
		return ans;
	}
}
