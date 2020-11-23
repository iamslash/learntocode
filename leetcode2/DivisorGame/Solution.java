// Copyright (C) 2020 by iamslash

import java.util.Map;
import java.util.HashMap;

// 5ms 13.88% 37.1MB 6.67%
// dynamic programming
// O(N^2) O(N)
class Solution {
	private Map<Integer, Boolean> C = new HashMap<>();
	public boolean divisorGame(int N) {
		// base
		if (N == 1)
			return false;
		else if (N == 2)
			return true;
		// memo
		if (C.containsKey(N))
			return C.get(N);
		// recursion
		C.put(N, false);
		for (int i = 1; i < N; ++i) {
			if (N % i == 0 && divisorGame(N-i) == false) {
				C.put(N, true);
				return true;
			}
		}
		return C.get(N);
	}
}
