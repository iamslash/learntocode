// Copyright (C) 2021 by iamslash

import java.util.*;

// 1ms 100.00% 39.4MB 100.00%
// linear traversal
// O(N) O(N)
class Solution {
	public int[] getConcatenation(int[] nums) {
		int n = nums.length;
		int[] ans = new int[n*2];
		for (int i = 0; i < n; ++i) {
			ans[i] = nums[i];
			ans[i+n] = nums[i];
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
