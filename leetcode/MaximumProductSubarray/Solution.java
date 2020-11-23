// Copyright (C) 2020 by iamslash

import java.util.*;

//            i
//    A: 2 3 -2 4
//    m: 2 3-12 
//    M: 2 6
// gMax: 2 6

// 1ms 91.05% 38.8MB 33.40%
// dynamic programming
// O(N) O(1)
class Solution {
	public int maxProduct(int[] A) {
		int gMax = A[0];
		int lastMax = A[0];
		int lastMin = A[0];
		for (int i = 1; i < A.length; ++i) {
			int tMin = Math.min(lastMin * A[i], lastMax * A[i]);
			int tMax = Math.max(lastMin * A[i], lastMax * A[i]);
			lastMin = Math.min(A[i], tMin);
			lastMax = Math.max(A[i], tMax);
			gMax = Math.max(gMax, lastMax);
		}
		return gMax;
	}
}
