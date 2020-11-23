// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36.2MB 100.00%
// math
// O(lg_10_N) O(1)
class Solution {
	public int subtractProductAndSum(int n) {
		int prd = 1, sum = 0;
		while (n > 0) {
			int d = n % 10;
			prd *= d;
			sum += d;
			n /= 10;
		}
		return prd - sum;
	}
}
