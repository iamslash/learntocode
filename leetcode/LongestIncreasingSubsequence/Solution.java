// Copyright (C) 2020 by iamslash

import java.util.*;

// 7ms 72.72% 42.4MB 5.60%
// binary search
// O(NlgN) O(N)
class Solution {
	public int lengthOfLIS(int[] nums) {
		List<Integer> lis = new ArrayList<>(nums.length);
		for (int num : nums) {
			int pos = Collections.binarySearch(lis, num);
			if (pos < 0) {
				pos = ~pos;
			}
			if (pos == lis.size()) {
				lis.add(num);
			} else {
				lis.set(pos, num);
			}					
		}
		return lis.size();
	}
}
