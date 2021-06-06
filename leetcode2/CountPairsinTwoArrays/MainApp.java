// Copyright (C) 2021 by iamslash

import java.util.*;

// nums1: 2 1 2 1
// nums2: 1 2 1 2

// nums1[i] + nums1[j] > nums2[i] + nums2[j]
// nums1[i] - nums2[i] > nums2[j] - nums1[j]
// nums1[i] - nums2[i] > -(nums1[j] - nums2[j])
//             diff[i] > -diff[j]
//   diff[i] + diff[j] > 0

// nums1: 1 10 6 2
// nums2: 1  4 1 5
// diffs:  0  6 -5 -3
//                  i
//        -5 -3  0  6
//               j
//   cnt: 2

// 21ms 100.00% 48.2MB 93.33%
// sort, two pointers
// O(NlgN) O(N)
class Solution {
	public long countPairs(int[] nums1, int[] nums2) {
		int n = nums1.length;
		int[] diffs = new int[n];
		for (int i = 0; i < n; ++i) {
			diffs[i] = nums1[i] - nums2[i];
		}
		Arrays.sort(diffs);
		int j = n - 1;
		long cnt = 0;
		for (int i = 0; i < n; ++i) {
			while (i < j && diffs[i] + diffs[j] > 0) {
				--j;
			}
			if (j >= i) {
				cnt += n - j - 1;
			} else {
				cnt += n - i - 1;
			}
		}
		return cnt;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
