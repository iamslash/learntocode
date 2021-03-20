// Copyright (C) 2021 by iamslash

import java.util.*;

//          i
//       A: 5 1 3 4 2
//  higher:     t t t
//   lower:   t t   t
// jumpMap: 2 3 4
//          4 2 3
//     ans: 2

// 57ms 87.02% 46MB 51.79%
// Sorted Map
// O(NlgN) O(N)
class Solution {
	public int oddEvenJumps(int[] arr) {
		int n = arr.length, ans = 1;
		boolean[] higher = new boolean[n];
		boolean[] lower = new boolean[n];
		higher[n-1] = lower[n-1] = true;
		TreeMap<Integer, Integer> jumpMap = new TreeMap<>();
		jumpMap.put(arr[n-1], n-1);
		for (int i = n-2; i >= 0; --i) {
			Map.Entry<Integer, Integer> hiFirst = jumpMap.ceilingEntry(arr[i]);
			Map.Entry<Integer, Integer> loFirst = jumpMap.floorEntry(arr[i]);
			if (hiFirst != null) {
				higher[i] = lower[(int)hiFirst.getValue()];
			}
			if (loFirst != null) {
				lower[i] = higher[(int)loFirst.getValue()];
			}
			if (higher[i]) {
				ans++;
			}
			jumpMap.put(arr[i], i);
		}
		return ans;
	}
}
