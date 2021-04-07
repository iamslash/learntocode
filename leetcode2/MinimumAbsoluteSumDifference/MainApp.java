// Copyright (C) 2021 by iamslash

import java.util.*;

//          
//            j
//  sorted: 1 5 7
//            i
//   nums1: 1 7 5
//   nums2: 2 3 5
// diffsum: 5
// maxdiff: 2 


// 59ms 59.98% 57.4MB 65.35%
// binary search
// O(NlgN) O(N)
class Solution {
	private final int MOD = 1_000_000_007;
	public int minAbsoluteSumDiff(int[] nums1, int[] nums2) {
		int[] sorted = nums1.clone();
		Arrays.sort(sorted);
		int maxdiff = Integer.MIN_VALUE;
		long diffsum = 0;
		for (int i = 0; i < nums2.length; ++i) {
			int diff = Math.abs(nums1[i] - nums2[i]);
			diffsum += diff;
			int j = Arrays.binarySearch(sorted, nums2[i]);
			if (j < 0) {
				j = ~j;
			}
			if (j < nums1.length) {
				maxdiff = Math.max(
						maxdiff, diff - Math.abs(sorted[j] - nums2[i]));
			}
			if (j > 0) {
				maxdiff = Math.max(
						maxdiff, diff - Math.abs(sorted[j-1] - nums2[i]));
			}			
		}
		return (int)((diffsum - maxdiff) % MOD);
	}
}

class MainApp {
	public static void main(String[] args) {
	}
}
