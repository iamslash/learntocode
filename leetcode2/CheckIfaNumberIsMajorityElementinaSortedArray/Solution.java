// Copyright (C) 2020 by iamslash

// 0ms 100.00% 37.7MB 100.00%
// binary search
// O(lgN) O(1)
class Solution {
	public boolean isMajorityElement(int[] A, int T) {
		int n = A.length, l = 0, m = 0, h = n-1;
		while (l < h) {
			m = l + (h - l)/2;
			if (A[m] < T)
				l = m + 1;
			else
				h = m;
		}
		if (A[l] != T)
			return false;
		int cnt = 0;
        // System.out.printf("l:%d, h:%d\n", l, h);
		while (l >= 0 && A[l] == T) {
            --l;
			cnt++;
		}
		while (h + 1 < n && A[h+1] == T) {
            ++h;
			cnt++;
		}
		return cnt > n/2;
	}
}
