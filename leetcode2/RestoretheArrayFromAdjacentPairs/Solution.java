// Copyright (C) 2021 by iamslash

import java.util.*;

// 203ms 57.39% 174.2MB 47.83%
class Solution {
	public int[] restoreArray(int[][] E) {
		int n = E.length;
		Map<Integer, List<Integer>> adjMap = new HashMap<>();
		List<Integer> ans = new ArrayList<>();
		for (int[] e : E) {	
			int u = e[0], v = e[1];		
			adjMap.putIfAbsent(u, new ArrayList<>());
			adjMap.putIfAbsent(v, new ArrayList<>());
			adjMap.get(u).add(v);
			adjMap.get(v).add(u);
		}
    // System.out.println(adjMap);
		for (Integer k : adjMap.keySet()) {
			if (adjMap.get(k).size() == 1) {
				ans.add(k);
				ans.add(adjMap.get(k).get(0));
        break;
			}
		}
    // System.out.println(ans);
		while (ans.size() <= n) {
			int tail = ans.get(ans.size()-1);
			int prev = ans.get(ans.size()-2);
			List<Integer> adjNums = adjMap.get(tail);
			if (adjNums.get(0) != prev) {
				ans.add(adjNums.get(0));
			} else {
				ans.add(adjNums.get(1));
			}
		}
		return ans.stream()
				.mapToInt(Integer::intValue)
				.toArray();
	}
}
