// Copyright (C) 2020 by iamslash

// p * q (p >= q)

// 5ms 94.48% 37.1MB 100.00%
// math
// O(N) O(1)
class Solution {
	public int[] closestDivisors(int num) {
		int sqrtn = (int)Math.sqrt(num+2);
		for (int p = sqrtn; p > 0; --p) {
			if ((num + 1) % p == 0)
				return new int[]{p, (num+1)/p};
			if ((num + 2) % p == 0)
				return new int[]{p, (num+2)/p};
		}
		return new int[]{};
	}
}
