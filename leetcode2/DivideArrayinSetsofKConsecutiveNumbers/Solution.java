// Copyright (C) 2020 by iamslash

import java.util.TreeMap;
import java.util.List;
import java.util.ArrayList;

// // 187ms 24.19%
// // sorted map
// // O(N) O(N)
// import java.util.SortedMap;
// class Solution {
// 	public boolean isPossibleDivide(int[] A, int K) {
// 		SortedMap<Integer, Integer> cnts = new TreeMap<>();
// 		for (int a : A) {
// 			cnts.put(a, cnts.getOrDefault(a, 0) + 1);
// 		}
// 		for (int k : cnts.keySet()) {
// 			if (cnts.get(k) > 0) {
// 				for (int i = K - 1; i >= 0; --i) {
// 					if (cnts.getOrDefault(k + i, 0) < cnts.get(k))
// 						return false;
// 					cnts.put(k + i, cnts.get(k + i) - cnts.get(k));
// 				}
// 			}
// 		}
// 		return true;
// 	}
// }

// 3ms 100.00% 49.4% 100.00%
// hash map
// O(N) O(K)
class Solution {
	public boolean isPossibleDivide(int[] A, int K) {
		int n = A.length;
		if (n % K != 0)
			return false;
		int s = n / K;
		int[] cnts = new int[K];
		for (int a : A) {
			cnts[a % K]++;
		}
		for (int c : cnts) {
			if (c != s)
				return false;
		}
		return true;
	}
}
