// Copyright (C) 2020 by iamslash

import java.util.*;

// dynamic programming
// 1ms 100.00% 36.8MB 67.13%
class Solution {
	public int findIntegers(int num) {
		StringBuilder sb = new StringBuilder(Integer.toBinaryString(num)).reverse();
		int n = sb.length();

		int a[] = new int[n];
		int b[] = new int[n];
		a[0] = b[0] = 1;
		for (int i = 1; i < n; ++i) {
			a[i] = a[i-1] + b[i-1];
			b[i] = a[i-1];
		}
		int ans = a[n-1] + b[n-1];
		for (int i = n - 2; i >=0; i--) {
			if (sb.charAt(i) == '1' && sb.charAt(i+1) == '1')
				break;
			if (sb.charAt(i) == '0' && sb.charAt(i+1) == '0')
				ans -= b[i];
		}
		return ans;											
	}
}
