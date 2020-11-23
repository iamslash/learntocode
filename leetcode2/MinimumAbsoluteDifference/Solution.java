// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.Arrays;
import java.util.ArrayList;

// 14ms 98.40% 51MB 100.00%
// sort
// O(NlgN) O(N)
class Solution {
	public List<List<Integer>> minimumAbsDifference(int[] A) {
		Arrays.sort(A);
		int minDiff = Integer.MAX_VALUE;
		List<List<Integer>> ans = new ArrayList<>();
		for (int i = 1; i < A.length; ++i) {
			int diff = A[i] - A[i-1];
			if (diff < minDiff) {
				minDiff = diff;
				ans.clear();
				ans.add(Arrays.asList(A[i-1], A[i]));
			} else if (diff == minDiff) {
				ans.add(Arrays.asList(A[i-1], A[i]));
			}
		}
		return ans;
	}
}
