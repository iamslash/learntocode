// Copyright (C) 2020 by iamslash

// 0ms 100.00% 35.9MB 100.00%
// math
// O(N) O(1)
class Solution {
	private int getSteps(int n, long a, long b) {
		int steps = 0;
		while (a <= n) {
			steps += Math.min(n + 1, b) - a;
			a *= 10;
			b *= 10;
		}
		return steps;
	}
	public int findKthNumber(int n, int k) {
		int num = 1;
		k--;
		while (k > 0) {
			int steps = getSteps(n, num, num+1);
			if (steps <= k) {
				num += 1;
				k -= steps;
			} else {
				num *= 10;
				k -= 1;
			}			
		}
		return num;
	}
}
