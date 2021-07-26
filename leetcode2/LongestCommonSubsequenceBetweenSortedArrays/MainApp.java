// Copyright (C) 2021 by iamslash

import java.util.*;

// 2ms 78.00% 40.2MB 63.00%
// hash map
// O(N) O(N)
class Solution {
	public List<Integer> longestCommomSubsequence(int[][] arrays) {
		int bnd = arrays.length;
		int[] freqs = new int[101];
		List<Integer> ans = new ArrayList<>();
		for (int[] nums : arrays) {
			for (int num : nums) {
				if (++freqs[num] == bnd) {
					ans.add(num);
				}
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
