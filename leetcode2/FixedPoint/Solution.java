// Copyright (C) 2020 by iamslash

// 0ms 100.00% 39.2MB 50.00%
// binary search
// O(lgN) O(1)
class Solution {
	private int getSameNum(int[] A, int s) {
		while (s < A.length) {
			if (A[s] == s)
				return s;
            ++s;
		}
		return -1;
	}
	public int fixedPoint(int[] A) {
		int lo = 0, mi = 0, hi = A.length-1;
		while (lo < hi) {
			mi = lo + (hi - mi) / 2;
			if (A[mi] < 0) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
        // System.out.println(lo);
		return getSameNum(A, lo);
	}
}
