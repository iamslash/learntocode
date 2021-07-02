// Copyright (C) 2021 by iamslash

import java.util.*;

//  tgt: 3
//           l
// nums: 2 1 3
//           r
//  sum: 4
//  cnt: 4

// 25ms 100.00% 41.3MB 100.00%
// binary search, sliding window
// O(NlgN) O(1)
class Solution {
	// Get count of sum which is less than equal to tgtSum
	private int cntLessEqual(int[] nums, int tgtSum) {
		int cnt = 0, sum = 0, left = 0, n = nums.length;
		for (int right = 0; right < n; ++right) {
			sum += nums[right];
			while (sum > tgtSum) {
				sum -= nums[left++];
			}
			cnt += right - left + 1;
		}
		return cnt;
	}
	public int kthSmallestSubarraySum(int[] nums, int k) {
		int lo = 1, hi = 0, n = nums.length;
		for (int i = 0; i < n; ++i) {
			hi += nums[i];
		}
		while (lo < hi) {
			int mi = lo + (hi - lo)/2;
			if (cntLessEqual(nums, mi) < k) {
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
