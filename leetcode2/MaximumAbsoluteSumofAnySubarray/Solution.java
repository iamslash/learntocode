// Copyright (C) 2021 by iamslash

//  nums: -1 -1 -1 -1 -1
//    ps: -1 -2 -3 -4 -5
// maxPs: 0
// minPs: -5

//  nums: 0 1 -1 -1 -1
//    ps: 0 1  0 -1 -2
// maxPs: 0
// minPs: -5

// 2ms 100.00% 47.2MB 96.31%
// partial sum
// O(N) (1)
class Solution {
	public int maxAbsoluteSum(int[] nums) {
		int maxPs = 0, minPs = 0, ps = 0;
		for (int a : nums) {
			ps += a;
			maxPs = Math.max(maxPs, ps);
			minPs = Math.min(minPs, ps);
		}
		return maxPs - minPs;
	}
}
