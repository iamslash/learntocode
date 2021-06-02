// Copyright (C) 2021 by iamslash

import java.util.*;

// 50ms 88.57% 55.3MB 63.90%
// sort
// O(NlgN) O(N)
class Solution {
	public int minPairSum(int[] nums) {
		int n = nums.length;
		Arrays.sort(nums);
		int maxPair = 0;
		for (int i = 0; i < n/2; ++i) {
			maxPair = Math.max(maxPair, nums[i] + nums[n-1-i]);
		}
		return maxPair;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
