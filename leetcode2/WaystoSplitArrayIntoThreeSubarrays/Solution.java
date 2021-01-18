// Copyright (C) 2021 by iamslash

// 11ms 90.45% 48.9% 34.46%
// partial sum
// O(N) O(1)
class Solution {
	private final int MOD = 1000000007;
	public int waysToSplit(int[] nums) {
		int ans = 0, n = nums.length;
		for (int i = 1; i < n; ++i) {
			nums[i] += nums[i-1];
		}
		for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
			while (j <= i ||
						 (j < n-1 && nums[j] < nums[i] * 2)) {
				++j;
			}
			while (k < j ||
						 (k < n-1 &&
							nums[k] - nums[i] <= nums[n-1] - nums[k])) {
				++k;
			}
			ans = (ans + k - j) % MOD;
		}
		return ans;
	}
}
