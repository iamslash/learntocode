// Copyright (C) 2021 by iamslash

import java.util.*;

// i 
// 1 2 4 5 10

// 309ms 50.00% 73MB 100.00%
// hash map
// O(N^2) O(N)
class Solution {
	public int tupleSameProduct(int[] nums) {
		int ans = 0;
		Map<Integer, Integer> prodMap = new HashMap<>();
		for (int i = 0; i < nums.length; ++i) {
			for (int j = i+1; j < nums.length; ++j) {
				int prod = nums[i] * nums[j];
				ans += 8 * prodMap.getOrDefault(prod, 0);
				prodMap.put(prod, prodMap.getOrDefault(prod, 0) + 1);
			}
		}
		return ans;
	}
}
