// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 38.4MB 71.88%
// binary search
// O(lgN) O(1)
class Solution {
	public int findPeakElement(int[] nums) {
		int lo = 0;
		int hi = nums.length - 1;
		while (lo < hi) {
			int mi = (lo + hi) / 2;
			if (nums[mi] < nums[mi+1]) {
				lo = mi + 1;
			} else {
				hi = mi;
			}
		}
		return lo;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
