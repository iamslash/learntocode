// Copyright (C) 2020 by iamslash

// 
// C: 10
// P: 3
// i: 0
//
// ans: 0 0 0

// 1ms 91.44% 37.1MB 100.00%
// array
// O(N) O(N)
class Solution {
	public int[] distributeCandies(int C, int P) {
		int[] ans = new int[P];
		int i = 0;
		while (C > 0) {
			int delta = Math.min(C, i + 1);
			ans[i % P] += delta;
			C -= delta;
            ++i;
		}
		return ans;
	}
}
