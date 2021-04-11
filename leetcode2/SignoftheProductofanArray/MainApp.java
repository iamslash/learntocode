// Copyright (C) 2021 by iamslash

import java.util.*;

// 0ms 100.00% 38.7MB 50.00%
// linear traversal
// O(N) O(1)
class Solution {
	public int arraySign(int[] nums) {
		int nNeg = 0;
		for (int i = 0; i < nums.length; ++i) {
			if (nums[i] == 0) {
				return 0;
			}
			if (nums[i] < 0) {
				++nNeg;
			}				
		}
		return nNeg % 2 == 1 ? -1 : 1;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
