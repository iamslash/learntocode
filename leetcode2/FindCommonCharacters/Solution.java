// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

// 2ms 97.04% 39.8MB 17.24%
// hashmap
// O(N) O(N)
class Solution {
	public List<String> commonChars(String[] A) {
		List<String> ans = new ArrayList<>();
		int[] minCnt = new int[26];
		Arrays.fill(minCnt, Integer.MAX_VALUE);
		for (String s : A) {
			int[] cnt = new int[26];
			Arrays.fill(cnt, 0);
			for (char c : s.toCharArray()) {
				cnt[c - 'a']++;
			}
			for (int i = 0; i < 26; ++i) {
				minCnt[i] = Math.min(minCnt[i], cnt[i]);
			}
		}
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < minCnt[i]; ++j) {
				ans.add(String.valueOf((char)(i + 'a')));
			}
		}
		return ans;
	}
}
