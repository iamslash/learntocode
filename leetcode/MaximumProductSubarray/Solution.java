// Copyright (C) 2021 by iamslash

import java.util.*;

//   
//   nums: 2 3 -2  4
//                 i
// tmpMin: 2 6-12-48 
// tmpMax: 2 6 -6 -8
// locMin: 2 3-12-48 
// locMax: 2 6 -2  4
// glbMax: 2 6  6  6

// 1ms 93.81% 39.1MB 30.86%
// iterative dynamic programming
// O(N) O(1)
class Solution {
	public int maxProduct(int[] nums) {
		int glbMax = Integer.MIN_VALUE, n = nums.length;
		int locMin = 1;
		int locMax = 1;
		for (int num : nums) {
			int tmpMin = Math.min(locMin * num, locMax * num);
			int tmpMax = Math.max(locMin * num, locMax * num);
			locMin = Math.min(tmpMin, num);
			locMax = Math.max(tmpMax, num);
			glbMax = Math.max(glbMax, locMax);
		}
		return glbMax;
	}
}
