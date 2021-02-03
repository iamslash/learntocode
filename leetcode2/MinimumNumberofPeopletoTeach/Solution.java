// Copyright (C) 2021 by iamslash

import java.util.*;

// Time Limit Exceeded
// greedy, hash map, hash set
class Solution {
	private boolean isCommon(HashSet<Integer> aSet, HashSet<Integer> bSet) {
		for (int lang : aSet) {
			if (bSet.contains(lang)) {
				return true;
			}
		}
		return false;
	}
	private int minUsersToTeach(int lang, int[][] friendships,
									HashMap<Integer, HashSet<Integer>> langMap) {
		HashSet<Integer> minUsers = new HashSet<>();
		for (int i = 0; i < friendships.length; ++i) {
			int u = friendships[i][0];
			int v = friendships[i][1];
			HashSet<Integer> uLangSet = langMap.get(u);
			HashSet<Integer> vLangSet = langMap.get(v);
			if (!isCommon(uLangSet, vLangSet)) {
				if (!uLangSet.contains(lang)) {
					minUsers.add(u);
				}
				if (!vLangSet.contains(lang)) {
					minUsers.add(v);
				}
			}
		}
		return minUsers.size();
	}
	public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
		// {person: {language,...}}
		HashMap<Integer, HashSet<Integer>> langMap = new HashMap<>();
		for (int i = 0; i < languages.length; ++i) {
			langMap.put(i+1, new HashSet<>());
			for (int lang : languages[i]) {
				langMap.get(i+1).add(lang);
			}
		}
		int ans = languages.length;
		for (int i = 1; i <= n; ++i) {
			ans = Math.min(ans, minUsersToTeach(i, friendships, langMap));
		}
		return ans;
	}
}
