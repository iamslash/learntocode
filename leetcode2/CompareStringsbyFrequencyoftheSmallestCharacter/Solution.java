// Copyright (C) 2020 by iamslash

// 2ms 91.51% 39.5MB 100.00%
// hash map
// O(N) O(N)
class Solution {
	private int f(String s) {
		char minChar = 'z'+1;
		int  minCnt = 0;
		for (Character c : s.toCharArray()) {
			if (c < minChar) {
				minChar = c;
				minCnt = 1;
			} else if (c == minChar) {
				++minCnt;
			}
		}
		return minCnt;
	}
	public int[] numSmallerByFrequency(String[] Q, String[] W) {
		int[] cntF = new int[11];
		for (String word : W) {
			int n = f(word);
			for (int i = 0; i < n; ++i) {
				cntF[i]++;
			}
		}
		int[] ans = new int[Q.length];
		for (int i = 0; i < Q.length; ++i) {
			ans[i] = cntF[f(Q[i])];
		}
		return ans;
	}
}
