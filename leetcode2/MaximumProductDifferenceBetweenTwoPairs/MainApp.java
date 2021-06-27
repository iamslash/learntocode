// Copyright (C) 2021 by iamslash

import java.util.*;

// // 6ms 40.00% 39.2MB 20.00%
// // sort
// // O(NlgN) O(1)
// class Solution {
// 	public int maxProductDifference(int[] nums) {
// 		int n = nums.length;
// 		Arrays.sort(nums);
// 		return nums[n-2]*nums[n-1] - nums[0]*nums[1];
// 	}
// }

// 1ms 100.00% 39MB 20.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int maxProductDifference(int[] nums) {
		int max1 = 0, max2 = 0, min1 = Integer.MAX_VALUE, min2 = Integer.MAX_VALUE;
		for (int num : nums) {
			if (num > max1) {
				int t = max1;
				max1 = num;
				max2 = t;
			} else if (num > max2) {
				max2 = num;
			}
			if (num < min1) {
				int t = min1;
				min1 = num;
				min2 = t;
			} else if (num < min2) {
				min2 = num;
			}
		}
		return max1 * max2 - min1 * min2;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
