// Copyright (C) 2020 by iamslash

// a: 0010
// b: 0110
//--------
// c: 0101
//
//    0011 0011
//     0101 0101
//--------
//    0000 1111
//    0112 1000

// bit manipulation
// O(1) O(1)
class Solution {
	public int minFlips(int a, int b, int c) {
		int ans = 0;
		while (a > 0 || b > 0 || c > 0) {
			int d = a & 1;
			int e = b & 1;
			int f = c & 1;
			if (d == 1 && e == 1 && f == 0) {
				ans += 2;
			} else if ((d == 0 && e == 1 && f == 0) ||
								 (d == 1 && e == 0 && f == 0) ||
								 (d == 0 && e == 0 && f == 1)) {
				ans += 1;
			}
			a >>= 1;
			b >>= 1;
			c >>= 1;
            // System.out.printf("%d %d %d\n", a, b, c);
		}
		return ans;
	}
}
