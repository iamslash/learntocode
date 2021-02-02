// Copyright (C) 2021 by iamslash

import java.util.*;
//       6: 110
//       5: 101
//       4: 100 
//
// enc:   6 5 4 6
// org: 2 4 1 5 3

//    perm: a0    a1    a2    ...       a_n-1 
// encoded:       a0^a1 a1^a2 a2^a3 ... a_n-2^a_n-1
//     all: a0^a1^a2^...^a_n-1
//      a0: all^(a1^a2)^(a3^a4)^...^(a_n-2^a_n-1)
//    perm: a0 a0^(a0^a1) a1^(a1^a2) ... a_n-2^(a_n-2^a_n-1)

// 6ms 22.75% 145.2MB 11.43%
// linear traversal
// O(N) O(N)
class Solution {
	public int[] decode(int[] encoded) {
		int all = 0, n = encoded.length+1;
		int[] ans = new int[n];
		for (int i = 1; i <= n; ++i) {
			all ^= i;
		}
		for (int i = 1; i < n-1; i+=2) {
			all ^= encoded[i];
		}
		ans[0] = all;
		for (int i = 1; i < n; ++i) {
			ans[i] = ans[i-1] ^ encoded[i-1];
		}
		return ans;
	}
}
