// Copyright (C) 2021 by iamslash

import java.util.*;

// LIS
class Solution {
	public int minOperations(int[] target, int[] arr) {
		Map<Integer, Integer> idxMap = new HashMap<>();
		for (int i = 0; i < target.length; ++i) {
			idxMap.put(target[i], i);
		}
		int lis = 0;
		int[] stack = new int[arr.length+1];
		for (int num : arr) {
			if (!idxMap.containsKey(num)) {
				continue;
			}
			int i = Arrays.binarySearch(stack, 0, lis, idxMap.get(num));
			i = Math.max(i, ~i);
			stack[i] = idxMap.get(num);
			lis = Math.max(lis, i + 1);
		}
		return target.length - lis;
	}
}
