// Copyright (C) 2021 by iamslash

import java.util.*;

// 2
// 3 4
// 7 6 7
// 4 1 8 3
// j

// 5ms 19.22% 37.6MB 97.43%
// iterative dynamic programming
// O(T^2) O(1)
class Solution {
	public int minimumTotal(List<List<Integer>> T) {
		int h = T.size();
		for (int i = h-1; i > 0; --i) {
			for (int j = 0; j < i; ++j) {
				T.get(i-1).set(j,
											 T.get(i-1).get(j) +
											 Math.min(T.get(i).get(j),
																T.get(i).get(j+1)));
			}
		}
		return T.get(0).get(0);
	}
}
