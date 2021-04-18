// Copyright (C) 2021 by iamslash

import java.util.*;

// nums: 1 1 1
//       0 0 0
// nums: 1 5 2 4 1
//       1 5 6 7 8
//           4 3 7

// 2ms 100.00% 45.5MB 100.00%
// brute force
// O(N) O(1)
class Solution {
	public int minOperations(int[] nums) {
		int cnt = 0;
		for (int i = 1; i < nums.length; ++i) {
			if (nums[i-1] >= nums[i]) {
				int newNum = nums[i-1]+1;
				cnt += newNum - nums[i];
				nums[i] = newNum;
			}
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
