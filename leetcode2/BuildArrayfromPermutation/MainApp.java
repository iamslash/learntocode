// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 40MB 100.00%
// brute force
// O(N) O(N)
class Solution {
	public int[] buildArray(int[] nums) {
		int n = nums.length;
		int[] ans = new int[n];
		for (int i = 0; i < n; ++i) {
			ans[i] = nums[nums[i]];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
