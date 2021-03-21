// Copyright (C) 2021 by iamslash

import java.util.*;

//                          i
//   nums: 10 20 30 5 10 50
//                          j
// locSum: 65 
// glbSum: 65

//    

// brute force
// O(N) O(1)
class Solution {
	public int maxAscendingSum(int[] nums) {
		int i = 0, j = 0, n = nums.length, glbSum = 0;
		while (j < n) {
			int locSum = nums[j++];
			while (j < n && nums[i] < nums[j]) {
				locSum += nums[j++];
			}
			glbSum = Math.max(glbSum, locSum);
			i = j;
		}
		return glbSum;
	}
}
