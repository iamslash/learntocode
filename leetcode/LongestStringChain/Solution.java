// Copyright (C) 2020 by iamslash

import java.util.*;

// dynamic programming
// O(NlgN) ON)
class Solution {
	public int longestStrChain(String[] W) {
		int glbmax = 0;
		Arrays.sort(W, (a, b) -> Integer.valueOf(a.length()).compareTo(b.length()));
    // System.out.println(Arrays.deepToString(W));
		Map<String, Integer> C = new HashMap<>();
		for (String word : W) {
			int locmax = 0;
			for (int i = 0; i < word.length(); ++i) {
				String t = word.substring(0, i) + word.substring(i+1);
				locmax = Math.max(locmax, C.getOrDefault(t, 0) + 1);
			}
			C.put(word, locmax);
			glbmax = Math.max(glbmax, locmax);
		}					
		return glbmax;
	}
}
