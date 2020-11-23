// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36.4MB 100.00%
// binary search
// O(lgN) O(1)
class Solution {
	private long gcd(long a, long b) {
		if (b == 0)
			return a;
		return gcd(b, a%b);
	}
	public int nthUglyNumber(int k, int A, int B, int C) {
		int lo   = 1, hi = 2 * (int)1e9, mi = 0;
		long a   = A, b = B, c = C;
		long ab  = a * b / gcd(a, b);
		long bc  = b * c / gcd(b, c);
		long ac  = a * c / gcd(a, c);
		long abc = a * bc / gcd(a, bc);
		while (lo < hi) {
			mi = lo + (hi - lo) / 2;
			long cnt = mi/a + mi/b + mi/c - mi/ab - mi/bc - mi/ac + mi/abc;
			if (cnt < k) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
		return lo;
	}
}
