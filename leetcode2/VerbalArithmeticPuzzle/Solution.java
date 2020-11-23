// Copyright (C) 2020 by iamslash

import java.util.*;

// 592ms 61.31% 36.8MB 99.27%
// backtracking
// O(n!) O(N)
class Solution {
	private static final int[] POW_10 = new int[]{1, 10, 100, 1000, 10000, 100000, 1000000};
	private boolean dfs(boolean[] used, char[] charList,
											boolean[] firstChar, int step,
											int diff, int[] charCnt) {
		// base
		if (step == charList.length)
			return diff == 0;
		// recursion
		for (int d = 0; d < 10; d++) {
			if (used[d])
				continue;
			char c = charList[step];
			if (d == 0 && firstChar[c])
				continue;																 
			used[d] = true;
			if (dfs(used, charList, firstChar, step+1,
							diff + charCnt[c] * d, charCnt))
				return true;
			used[d] = false;
		}
		return false;
	}
	public boolean isSolvable(String[] words, String result) {
		Set<Character> charSet = new HashSet<>();
		int[] charCnt = new int[91];
		boolean[] firstChar = new boolean[91];
		for (String word : words) {
			char[] chars = word.toCharArray();
			for (int i = 0; i < chars.length; ++i) {
				if (i == 0 && chars.length > 1)
					firstChar[chars[i]] = true;
				charSet.add(chars[i]);
				charCnt[chars[i]] += POW_10[chars.length - i - 1];
			}
		}
		char[] chars = result.toCharArray();
		for (int i = 0; i < chars.length; i++) {
			if (i == 0 && chars.length > 1)
				firstChar[chars[i]] = true;
			charSet.add(chars[i]);
			charCnt[chars[i]] -= POW_10[chars.length - i - 1];
		}
		boolean[] used = new boolean[10];
		char[] charList = new char[charSet.size()];
		int i = 0;
		for (char c : charSet)
			charList[i++] = c;
		return dfs(used, charList, firstChar, 0, 0, charCnt);
	}
}
