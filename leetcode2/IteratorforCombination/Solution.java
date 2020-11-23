// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// 13ms 48.51% 41.1MB 100.00%
// backtracking
// O(len^N) O(len)
class CombinationIterator {
	private List<String> data = new ArrayList<>();
	int idx = 0;

	private void dfs(String s, int len, StringBuilder combi, int beg) {
		// base
		if (len == 0) {
			data.add(combi.toString());
			return;
		}
		// recursion
		for (int i = beg; i <= s.length() - len; ++i) {
			combi.append(s.charAt(i));
			dfs(s, len-1, combi, i+1);
			combi.deleteCharAt(combi.length()-1);
		}
	}

	public CombinationIterator(String s, int n) {
		dfs(s, n, new StringBuilder(), 0);
	}
    
	public String next() {	 
    return data.get(idx++);
	}
    
	public boolean hasNext() {
    return idx < data.size();
	}
}

