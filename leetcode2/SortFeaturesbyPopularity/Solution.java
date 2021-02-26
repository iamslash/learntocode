// Copyright (C) 2021 by iamslash

import java.util.*;

// 63ms 100.00% 43.9MB 100.00%
// hash map
// O(N) O(N)
class Solution {
	public String[] sortFeatures(String[] features, String[] responses) {
		Map<String, Integer> idxMap = new HashMap<>();
		Map<String, Integer> cntMap = new HashMap<>();
		for (int i = 0; i < features.length; ++i) {
			idxMap.put(features[i], i);
			cntMap.put(features[i], 0);
		}
		for (String res : responses) {
			String[] resArr = res.split(" ");
			Set<String> visitSet = new HashSet<>();
			for (String s : resArr) {
				if (!visitSet.contains(s) && cntMap.containsKey(s)) {
					cntMap.put(s, cntMap.get(s) + 1);
					visitSet.add(s);
				}
			}
		}
		Arrays.sort(features, (a, b) -> {
				int aFreq = cntMap.get(a);
				int bFreq = cntMap.get(b);
				if (aFreq == bFreq) {
					return idxMap.get(a).compareTo(idxMap.get(b));
				}
				return bFreq - aFreq;
			});
		return features;
	}
}
