// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// 35ms 78.32% 49MB 100.00%
// hash map
// O(N) O(N)
class Solution {
	public int minSetSize(int[] A) {
		Map<Integer, Integer> cnts = new HashMap<>();
		for (int a : A)
			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
		List<Integer> vals = new ArrayList<>(cnts.values());
		Collections.sort(vals, (a, b) -> b - a);
		int ans = 0, cntSum = 0, half = A.length/2;
		for (int val : vals) {
			ans++;
			cntSum += val;
			if (cntSum >= half)
				break;
		}
		return ans;
	}
}
