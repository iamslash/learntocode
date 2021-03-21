// Copyright (C) 2021 by iamslash

import java.util.*;

//                i
//   nums: 12 17 15 13 10 11 12
//                j
// locSum: 29 
// glbSum: 29

// 

// 0ms 100.00% 36.4MB 100.00%
// brute force
// O(N) O(1)
class Solution {
	public int maxAscendingSum(int[] nums) {
		int i = 0, n = nums.length, glbSum = 0;
		while (i < n) {
			int locSum = nums[i++];
			while (i < n && nums[i-1] < nums[i]) {
				locSum += nums[i++];
			}
			glbSum = Math.max(glbSum, locSum);
		}
		return glbSum;
	}
}

class Main {
	public static void main(String[] args) {
		Solution sln = new Solution();
		// 33
		int[] nums = {12,17,15,13,10,11,12};
		System.out.println(sln.maxAscendingSum(nums));
	}
}
