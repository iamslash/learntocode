// Copyright (C) 2020 by iamslash

import java.util.*;

//               i
//    s: ( ) ( ) ) ( )
//         j
// stck: 1 0 1 0 -
//  par: ( )   

//    s: ( ) ( ( ) ( )
//
// stck: 1 0 1 2 1 2 1
//  par: ( )

//    s: ) ( ) ( ( ) (
//
// stck: 1 0 1 0 -
//  par: ) (

// 1ms 99.93% 38.9MB 76.55%
// DFS
// O(N) O(N)
class Solution {
	private void dfs(String s, List<String> ans,
									 int lastI, int lastJ, char[] par) {
		for (int stck = 0, i = lastI; i < s.length(); ++i) {
			if (s.charAt(i) == par[0]) {
				stck++;
			}
			if (s.charAt(i) == par[1]) {
				stck--;
			}
			if (stck >= 0) {
				continue;
			}
			for (int j = lastJ; j <= i; ++j) {
				if (s.charAt(j) == par[1] &&
						(j == lastJ || s.charAt(j-1) != par[1])) {
					dfs(s.substring(0, j) + s.substring(j+1, s.length()),
							ans, i, j, par);
				}
			}
			return;
		}
		String reversed = new StringBuilder(s).reverse().toString();
		if (par[0] == '(') {
			dfs(reversed, ans, 0, 0, new char[]{')', '('});
		} else {
			ans.add(reversed);
		}
	}
	public List<String> removeInvalidParentheses(String s) {
		List<String> ans = new ArrayList<>();
		dfs(s, ans, 0, 0, new char[]{'(', ')'});
		return ans;
	}
}
