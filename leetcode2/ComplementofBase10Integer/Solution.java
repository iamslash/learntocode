// Copyright (C) 2020 by iamslash

// 0000 0101
//       111

// 0ms 100.00% 36.4MB 11.11%
// bit manipulation
// O(N) O(1)
class Solution {
	public int bitwiseComplement(int N) {
		int i = 1;
		while (i < N)
			i = (i << 1) + 1;
		return N ^ i;
	}
}
