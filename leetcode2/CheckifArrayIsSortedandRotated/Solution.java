// Copyright (C) 2021 by iamslash

import java.util.*;

//   i
// 2 1 3 4

// 0ms 100.00% 36.9MB 20.00%
// brute force
// O(N) O(N)
class Solution {
	public boolean check(int[] nums) {
		int n = nums.length;
		int[] merged = new int[2*n];
		System.arraycopy(nums, 0, merged, 0, n);
		System.arraycopy(nums, 0, merged, n, n);		
		int j = 0;
		for (int i = 0; i < n; ++i) {
			if (i > 0 && nums[i-1] > nums[i]) {
				j = i;
			}
		}
		for (int i = j+1; i < j+n; ++i) {
			if (merged[i-1] > merged[i]) {
				return false;
			}
		}
		return true;
	}
}

// i
// 2 1 3 4

// 0ms 100.00% 36.7MB 20.00%
// offset
// O(N) O(1)
class Solution {
	public boolean check(int[] nums) {
		int n = nums.length;
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (nums[i] > nums[(i+1)%n]) {
				c++;
			}
			if (c > 1) {
				return false;
			}
		}
		return true;
	}
}
