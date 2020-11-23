// Copyright (C) 2020 by iamslash

// 27ms 36.91% 41.9MB 100.00%
// binary search
// O(NlgN) O(1)
class Solution {
	private int getDivSum(int[] A, int k) {
		int ans = 0;
		for (int a : A) {
			ans += (int)Math.ceil((double)a / k);
		}
		return ans;
	}
	public int smallestDivisor(int[] A, int threshold) {
		int l = 1, h = (int)1e6;
		while (l < h) {
			int m = l + (h - l) / 2;
			if (getDivSum(A, m) > threshold) {
				l = m+1;
			} else {
				h = m;
			}
		}
		return l;
	}
}
