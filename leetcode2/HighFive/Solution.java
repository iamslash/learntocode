// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;


// 17ms 5.22% 40.8MB 100.00%
// hash map
// O(N) O(N)
class Solution {
	public int[][] highFive(int[][] items) {
		Map<Integer, List<Integer>> highFives = new HashMap<>();
		for (int[] item : items) {            
			int k = item[0];
			int score = item[1];
            
			if (!highFives.containsKey(k)) {
				highFives.put(k, new ArrayList<Integer>());
			}
			List<Integer> l = highFives.get(k);
			if (l.isEmpty()) {
				l.add(score);
				continue;
			}
			int i = 0;
			for (i = 0; i < l.size(); ++i) {
				if (score > l.get(i)) {
					l.add(i, score);
					break;
				}
			}
			if (i == l.size()) {
                l.add(i, score);
			} 
			while (l.size() > 5) {
				l.remove(5);
			}
		}
		List<int[]> ans = new ArrayList<>();
		highFives.forEach((a, b) -> {
            System.out.println(b);
				int avg = (int)b.stream().mapToInt(val -> val).average().getAsDouble();
				ans.add(new int[]{a, avg});
			});
		return ans.toArray(new int[ans.size()][2]);
	}
}
