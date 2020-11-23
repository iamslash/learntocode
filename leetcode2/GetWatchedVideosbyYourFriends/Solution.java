// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Collections;
import java.util.HashMap;

// BFS, sort
// O(NlgN) O(N)
class Solution {
	public List<String> watchedVideosByFriends(
			List<List<String>> V, int[][] F, int id, int lv) {
		Set<Integer> seen = new HashSet<>();
		List<Integer> q = new ArrayList<>();
		q.add(id);
		seen.add(id);
		for (int i = 0; i < lv; ++i) {
			List<Integer> qq = new ArrayList<>();
			for (int u : q) {
				for (int v : F[u]) {
					if (!seen.contains(v)) {
						seen.add(v);
						qq.add(v);
					}
				}
			}
			q = qq;
		}
		HashMap<String, Integer> cnts = new HashMap<>();
		for (int u : q) {
			for (String video : V.get(u))
				cnts.put(video, cnts.getOrDefault(video, 0) + 1);
		}
		List<String> ans = new ArrayList<>(cnts.keySet());
		Collections.sort(ans, (a, b) -> {
				if (cnts.get(a) == cnts.get(b))
    				return a.compareTo(b);
				return cnts.get(a) - cnts.get(b);
			});
		return ans;
	}
}
