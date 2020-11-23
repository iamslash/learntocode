// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

// 4ms 64.37% 40.3MB 100.00%
// reverse
// O(N) O(N)
class Solution {
	public List<Integer> addToArrayForm(int[] A, int K) {
		List<Integer> ans = new ArrayList<>();
		for (int i = A.length - 1; i >= 0 || K > 0; --i) {
			int num = K;
			if (i >= 0) {
				num += A[i];
			}
			ans.add(num % 10);
			K = num / 10;
		}
		Collections.reverse(ans);
		return ans;
	}
}
