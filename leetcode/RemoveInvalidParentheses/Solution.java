// Copyright (C) 2020 by iamslash

import java.util.*;

// 0) Understand the problem
//    s: ( ) ( ) ) ( )
//       (   ( ) ) ( )
//       ( ) (   ) ( )

// 1) How to decide invalid parentheses
//       i
//    s: ( ) )
//  bal: -1
//       i
//    s: ( ( )
//  bal: 1
//           i
//    s: ) ( (
//  bal: -1

// 2) How to remove invalid one
//               i
//    s: ( ) ( ) ) ( )
//             j
//  bal: -1
//       (   ( ) ) ( )
//       ( ) (   ) ( )

// 3) design subproblem
// void dfs(String s, List<String> ans, int lastI, int lastJ, 
//          char parInc, char parDec)

// 4) recursion tree

// 5) 

// 1ms 99.93% 38.9MB 76.55%
// DFS
// O(N) O(N)
class Solution {
	private void dfs(String s, List<String> ans,
									 int lastI, int lastJ, char parInc, char parDec) {
		for (int bal = 0, i = lastI; i < s.length(); ++i) {
			if (s.charAt(i) == parInc) {
				bal++;
			}
			if (s.charAt(i) == parDec) {
				bal--;
			}
			if (bal >= 0) {
				continue;
			}
			// s is invalid
			for (int j = lastJ; j <= i; ++j) {
				if (s.charAt(j) == parDec &&
						(j == lastJ || s.charAt(j-1) != parDec)) {
					dfs(s.substring(0, j) + s.substring(j+1),
							ans, i, j, parInc, parDec);
				}
			}
			// already handled in recursion and prevent overlapping
			return;
		}
		// s is ok
		String r = new StringBuilder(s).reverse().toString();
		if (parInc == '(') {
			// check reversed s
			dfs(r, ans, 0, 0, parDec, parInc);
		} else { 
			// forwarded, reversed s is valid
			ans.add(r);
		}
	}
	public List<String> removeInvalidParentheses(String s) {
		List<String> ans = new ArrayList<>();
		dfs(s, ans, 0, 0, '(', ')');
		return ans;
	}
}
