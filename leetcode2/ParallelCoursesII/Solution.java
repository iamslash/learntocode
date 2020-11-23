// Copyright (C) 2020 by iamslash

import java.util.*;

//    n: 4
//    E: 2,1 3,1 1,4
//    k: 2
//
//               .         .         .
//        C: 0 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4
//           i
//     prnt: 12 0 0 2
//              j
// canStudy: 0
//        

// 91ms 58.60% 38.5MB 86.56%
// iterative dynamic programming
// O(N^2) O(N)
class Solution {
	public int minNumberOfSemesters(int n, int[][] E, int k) {
		int[] prnt = new int [n];
		for (int[] e : E) {
			int u = e[0] - 1;
			int v = e[1] - 1;
			prnt[v] |= 1 << u;
		}
		// C[i] is minimum cost for bit mask i subjects
		int[] C = new int[1 << n];
		Arrays.fill(C, n);
		C[0] = 0;
		for (int u = 0; u < (1 << n); ++u) {
			int canStudy = 0;
			for (int j = 0; j < n; ++j) {
				// a & b == b, b is subset of a
				int v = prnt[j];
				if ((u & v) == v) {
					canStudy |= (1 << j);							
				}
			}
			canStudy &= ~u;
			for (int sub = canStudy; sub > 0; sub = (sub - 1) & canStudy) {
				if (Integer.bitCount(sub) <= k) {
					C[u | sub] = Math.min(C[u | sub], C[u] + 1);
				}
			}			
		}
		return C[(1 << n) - 1];
	}
}
