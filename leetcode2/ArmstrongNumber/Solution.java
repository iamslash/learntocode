// Copyright (C) 2020 by iamslash

// 0ms 100.00% 36MB 100.00%
// math
// O(N) O(1)
class Solution {
	public boolean isArmstrong(int N) {
		int ans = 0, n = N, k = 0;
		while (n > 0) {
			++k;
			n /= 10;
		}
		n = N;
		while (n > 0) {
			int r = 1;
			int d = n % 10;
			for (int j = 0; j < k; ++j)
				r = r * d; 
			ans += r;
			n /= 10;
		}        
		return ans == N;
	}
}
