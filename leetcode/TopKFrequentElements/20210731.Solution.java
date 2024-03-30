// Copyright (C) 2020 by iamslash

import java.util.*;

// 21ms 18.21% 47.7MB 8.22%
// bucket list
// O(N) O(N)
class Solution {
	public int[] topKFrequent(int[] A, int k) {
		// {freq : [num,...]}
		List<Integer>[] bucketList = new List[A.length+1];
		Map<Integer, Integer> freqMap = new HashMap<Integer, Integer>();
		for (int a : A) {
			freqMap.put(a, freqMap.getOrDefault(a, 0) + 1);
		}
		for (int num : freqMap.keySet()) {
			int freq = freqMap.get(num);
			if (bucketList[freq] == null)
				bucketList[freq] = new ArrayList<>();
			bucketList[freq].add(num);
		}
		List<Integer> ans = new ArrayList<>();
		for (int i = bucketList.length - 1; i >= 0; --i) {
			if (bucketList[i] != null) {
				for (int j = 0; j < bucketList[i].size() && ans.size() < k; j++)
					ans.add(bucketList[i].get(j));
			}
		}
		return ans.stream().mapToInt(i->i).toArray();
	}
}
