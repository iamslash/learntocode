// Copyright (C) 2020 by iamslash

import java.util.*;

// 15ms 99.79% 5.3MB 61.20%
// greedy algorithm
// O(N) O(N)
class Solution {
	public int stoneGameVI(int[] A, int[] B) {
		int alicePt = 0, bobPt = 0, n = A.length;
		boolean aliceTurn = true;
		List<Integer>[] idxs = new ArrayList[201];
		for (int i = 0; i < n; ++i) {
			int sum = A[i] + B[i];
			if (idxs[sum] == null)
				idxs[sum] = new ArrayList<>();
			idxs[sum].add(i);
		}
		for (int sum = 200; sum >= 0; --sum) {
			if (idxs[sum] == null)
				continue;
			for (int idx : idxs[sum]) {
				if (aliceTurn) {
					alicePt += A[idx];
				} else {
					bobPt += B[idx];
				}
				aliceTurn = !aliceTurn;				
			}							 
		}
		return alicePt == bobPt ? 0 : alicePt > bobPt ? 1 : -1;
	}
}
