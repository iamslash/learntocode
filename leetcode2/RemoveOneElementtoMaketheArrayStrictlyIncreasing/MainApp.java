// Copyright (C) 2021 by iamslash

import java.util.*;

//        i
// 1 2 1 10 7
//        .

// 0ms 100.00% 38.7MB 100.00%
// linear travsersal
// O(N) O(1)
class Solution {
	public boolean canBeIncreasing(int[] nums) {
		int removeCnt = 0;
		for (int i = 1; i < nums.length; ++i) {
			if (nums[i-1] >= nums[i]) {
				if (removeCnt > 0) {
					return false;
				}
				removeCnt++;
				if (i > 1 && nums[i-2] >= nums[i]) {
					nums[i] = nums[i-1];
				}
			}
		}
		return true;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
