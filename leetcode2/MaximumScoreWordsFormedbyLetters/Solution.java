// Copyright (C) 2020 by iamslash

import java.util.Arrays;

// 1ms 96.44% 39.1MB 100.00%
// DFS
// O(W^2S) O(W), S: max(W[i])
class Solution {
	private int dfs(String[] W, int[] cnts, int[] S, int i) {
		// base
		if (i >= W.length)
			return 0;
		int scoreSkip = dfs(W, cnts, S, i+1);
		int score = 0;
		boolean valid = true;
		int[] cnts2 = Arrays.copyOf(cnts, cnts.length);
		for (int j = 0; j < W[i].length(); ++j) {
			char c = W[i].charAt(j);
			if (--cnts2[c-'a'] < 0)
				valid = false;
			score += S[c-'a'];
		}
		int scoreInclude = 0;
		if (valid) {
			scoreInclude = score + dfs(W, cnts2, S, i+1);
		}
		return Math.max(scoreSkip, scoreInclude);
	}
	public int maxScoreWords(String[] words, char[] letters, int[] score) {
		int[] cnts = new int[26];
		for (char c : letters)
			cnts[c-'a']++;
		return dfs(words, cnts, score, 0);
	}
}
