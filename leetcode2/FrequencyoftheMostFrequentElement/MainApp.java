// Copyright (C) 2021 by iamslash

import java.util.*;

//    k: 5
// nums: 1 2 4 
//       0 1 3

//    k: 5
// nums: 1 4 8 13
//       0 3 7 12

// 26ms 72.45% 55.5MB 25.47%
// sort, sliding window
// O(NlgN) O(1)
class Solution {
	public int maxFrequency(int[] nums, int k) {
		Arrays.sort(nums);
		int i = 0, n = nums.length, ans = 1, sum = 0;
		for (int j = 0; j < n; ++j) {
			sum += nums[j];
			while ((j - i + 1) * nums[j] - sum > k) {
				sum -= nums[i++];
			}
			ans = Math.max(ans, j - i + 1);
		}
		return ans;
	}
}

// 25ms 94.78% 55.5MB 25.24%
// sort, sliding window
// O(NlgN) O(1)
class Solution {
	public int maxFrequency(int[] nums, int k) {
		Arrays.sort(nums);
		int i = 0, j = 0, n = nums.length, sum = 0;
		for (; j < n; ++j) {
			sum += nums[j];
			if ((j - i + 1) * nums[j] - sum > k) {
				sum -= nums[i++];
			}
		}
		return j - i;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
