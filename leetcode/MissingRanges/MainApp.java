// Copyright (C) 2021 by iamslash

import java.util.*;

//   lo: 0
//   hi: 99
//       c
// nums: 0 1 3 50 75
//       i

// 6ms 60.14% 38MB 5.53%
// linear traversal
// O(N) O(N)
class Solution {
	private String getRange(int s, int e) {
		if (s == e) {
			return String.valueOf(s);
		}
		return String.format("%d->%d", s, e);
	}
	public List<String> findMissingRanges(int[] nums, int lo, int hi) {
		List<String> ans = new ArrayList<String>();
		int next = lo, n = nums.length;
		for (int i = 0; i < n; ++i) {
			if (nums[i] < next) {
				continue;
			}
			if (nums[i] == next) {
				next++;
				continue;
			}
			ans.add(getRange(next, nums[i]-1));
			next = nums[i] + 1;
		}
		if (next <= hi) {
			ans.add(getRange(next, hi));
		}
		return ans;
	}
}

// 0ms 100.00% 36.7MB 99.62%
// linear traversal
// O(N) O(N)
class Solution {
	private String getRange(int s, int e) {
		if (s == e) {
			return String.valueOf(s);
		}
		StringBuilder sb = new Stringbuilder();
		sb.append(s);
		sb.append("->");
		sb.append(e);
		return sb.toString();
	}
	public List<String> findMissingRanges(int[] nums, int lo, int hi) {
		List<String> ans = new ArrayList<String>();
		int next = lo, n = nums.length;
		for (int i = 0; i < n; ++i) {
			if (nums[i] < next) {
				continue;
			}
			if (nums[i] == next) {
				next++;
				continue;
			}
			ans.add(getRange(next, nums[i]-1));
			next = nums[i] + 1;
		}
		if (next <= hi) {
			ans.add(getRange(next, hi));
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
