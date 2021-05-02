// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 38.6MB 22.22%
// two pointers, early return
// O(N) O(1)
class Solution {
	public int getMinDistance(int[] nums, int target, int start) {
		int i = start, j = start, n = nums.length;
		while (i >= 0 || j < n) {
			if (i >= 0) {
				if (nums[i] == target) {
					return start - i;
				}
				--i;
			}
			if (j < n) {
				if (nums[j] == target) {
					return j - start;
				}
				++j;
			}
		}
		return -1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
