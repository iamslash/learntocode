// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;

// 5ms 8.18% 47.9MB 9.09%
// bit manipulation
// O(N) O(N)
class Solution {
	public List<Boolean> prefixesDivBy5(int[] A) {
		int bm = 0;
		List<Boolean> ans = new ArrayList<>();
		for (int i = 0; i < A.length; ++i) {			
			bm = ((bm << 1) + A[i]) % 5;
			if (bm == 0)
				ans.add(true);
			else
				ans.add(false);
		}
		return ans;
	}
}
