// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 84.42% 39MB 86.40% 
// DFS
// O(2^N) O(N)
class Solution {
	private void dfs(List<String> ans,
									 String combi,
									 int leftCnt,
									 int ingCnt) {
		// base
		if (leftCnt == 0) {
			for (int i = 0; i < ingCnt; ++i) {
				combi += ")";
			}
			ans.add(combi);
			return;
		}
		// recursion
		if (ingCnt == 0) {
			dfs(ans, combi + "(", leftCnt - 1, ingCnt + 1);
		} else {
			dfs(ans, combi + "(", leftCnt - 1, ingCnt + 1);	
			dfs(ans, combi + ")", leftCnt, ingCnt - 1);		
		}
	}
	public List<String> generateParenthesis(int n) {
		List<String> ans = new ArrayList<>();
		dfs(ans, "", n, 0);
		return ans;
	}
}
