// Copyright (C) 2021 by iamslash

//         i
// nums: 2 2 1 1
//           a
//    C: t f t f  
//

// 12ms 87.34% 38.2MB 94.47%
// iterative dynamic programming
// O(HN) O(H)
class Solution {
	public boolean canPartition(int[] nums) {
		int sum = 0, n = nums.length;
		for (int i = 0; i < n; ++i) {
			sum += nums[i];
		}
		if (sum % 2 != 0) {
			return false;
		}
		int half = sum / 2;
		boolean[] C = new boolean[half+1];
		C[0] = true;
		for (int num : nums) {
			for (int amt = half; amt >= num; --amt) {
				if (!C[amt]) {
					C[amt] = C[amt - num];
				}
			}
		}
		return C[half];
	}
}
