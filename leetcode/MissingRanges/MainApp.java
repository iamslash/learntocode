// Copyright (C) 2021 by iamslash

import java.util.*;

//   lo: 0
//   hi: 99
//       c
// nums: 0 1 3 50 75
//       i

// 0ms 100.00% 37.1MB 91.09%
// linear traversal
// O(N) O(N)
class Solution {
	private String getRange(int s, int e) {
		if (s == e) {
			return String.valueOf(s);
		}
		StringBuilder sb = new StringBuilder();
		sb.append(s);
		sb.append("->");
		sb.append(e);
		return sb.toString();
	}
	public List<String> findMissingRanges(int[] nums, int lo, int hi) {
		List<String> ans = new ArrayList<String>();
		int miss = lo, n = nums.length;
		for (int num : nums) {
			if (miss < num) {
				ans.add(getRange(miss, num - 1));
			}
			miss = num + 1;
		}
		if (miss <= hi) {
			ans.add(getRange(miss, hi));
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
