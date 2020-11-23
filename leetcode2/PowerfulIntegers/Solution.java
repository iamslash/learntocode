// Copyright (C) 2020 by iamslash

import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.ArrayList;

// 1ms 95.68% 37.3MB 12.50%
// brute force
// O(N) O(N)
class Solution {
	public List<Integer> powerfulIntegers(int x, int y, int bnd) {
		Set<Integer> nums = new HashSet<>();
		for (int i = 1; i < bnd; i *= x) {
			for (int j = 1; i + j <= bnd; j *= y) {
				nums.add(i + j);
				if (y == 1)
					break;
			}
			if (x == 1)
				break;
		}
		return new ArrayList<>(nums);
	}
}
