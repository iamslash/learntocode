// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 99.90% 55.2MB 90.56%
// xor
// O(N) O(N)
class Solution {
	public int[] getMaximumXor(int[] nums, int maxBit) {
		int n = nums.length;
		int[] ans = new int[n];
		int cumVal = (1 << maxBit) - 1;
		for (int i = 0; i < n; ++i) {
			cumVal ^= nums[i];
			ans[n-i-1] = cumVal;
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
