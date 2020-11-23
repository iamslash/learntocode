// Copyright (C) 2020 by iamslash

// 0ms 100.00% 35.9MB 100.00%
class Solution {
	public int tribonacci(int n) {
		if (n == 0)
			return 0;
		else if (n == 1 || n == 2)
			return 1;
		int a = 0;
		int b = 1;
		int c = 1;
		while (n-- > 2) {
			int t = a + b + c;
			a = b;
			b = c;
			c = t;			
		}
		return c;
	}
}
