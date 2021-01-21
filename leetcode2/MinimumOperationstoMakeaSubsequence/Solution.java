// Copyright (C) 2021 by iamslash

import java.util.*;

// 65ms 92.69% 58.9MB 65.57%
// LIS
// O(NlgN) O(N)
class Solution {
	public int minOperations(int[] target, int[] arr) {
		Map<Integer, Integer> idxMap = new HashMap<>();
		for (int i = 0; i < target.length; ++i) {
			idxMap.put(target[i], i);
		}
		int lisCnt = 0;
		int[] lisArr = new int[arr.length+1];
		for (int num : arr) {
			if (!idxMap.containsKey(num)) {
				continue;
			}
			int i = Arrays.binarySearch(lisArr, 0, lisCnt, idxMap.get(num));
			// ~j: (-j) - 1
			i = Math.max(i, ~i);
			lisArr[i] = idxMap.get(num);
			lisCnt = Math.max(lisCnt, i + 1);
		}
		return target.length - lisCnt;
	}
}
