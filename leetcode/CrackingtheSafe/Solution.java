// Copyright (C) 2021 by iamslash

import java.util.*;

// dfs
// O(K^N) O(K^N)
class Solution {
	private boolean dfs(StringBuilder seq,
											Set<String> visit,
											int u, int n, intk) {
		// base
		if (visit.size() == u) {
			return true;
		}
		// recursion
		String lastDigit = seq.substring(seq.length() - n + 1);
		return false;
	}
	public String crackSafe(int n, int k) {
		StringBuilder seq = String.join("", Collections.nCopies(n, "0"));
		Set<String> visit = new HashSet<>();
		visit.add(seq);
		int u = (int) Math.pow(k, n);
		dfs(seq, visit, u, n, k);
		return seq.toString();
	}
}
