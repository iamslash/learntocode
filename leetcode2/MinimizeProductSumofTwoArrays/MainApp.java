// Copyright (C) 2021 by iamslash

import java.util.*;

// 202ms 5.42% 120.4MB 6.40%
// sort
// O(NlgN) O(N)
class Solution {
	public int minProductSum(int[] nums1, int[] nums2) {
		int n = nums1.length;
		Integer[] nums1Arr = new Integer[n], nums2Arr = new Integer[n];
		for (int i = 0; i < n; ++i) {
			nums1Arr[i] = nums1[i];
			nums2Arr[i] = nums2[i];
		}
		Arrays.sort(nums1Arr);
		Arrays.sort(nums2Arr, (a, b) -> b.compareTo(a));
		int prdSum = 0;
		for (int i = 0; i < n; ++i) {
			prdSum += nums1Arr[i] * nums2Arr[i];
		}
		return prdSum;
	}
}

// 3ms 100.00% 48.3MB 83.74%
// two pointers, hash map
// O(N) O(1)
class Solution {
	public int minProductSum(int[] nums1, int[] nums2) {
		int[] cnts1 = new int[101];
		int[] cnts2 = new int[101];
		for (int i = 0; i < nums1.length; i++) {
			cnts1[nums1[i]]++;
			cnts2[nums2[i]]++;
		}
		int idx1 = 100, idx2 = 0, sum = 0;
		while (idx1 >= 0 && idx2 <= 100) {
			if (cnts1[idx1] == 0) {
				idx1--;
			} else if (cnts2[idx2] == 0) {
				idx2++;
			} else {
				int minCnt = Math.min(cnts1[idx1], cnts2[idx2]);
				cnts1[idx1] -= minCnt;
				cnts2[idx2] -= minCnt;
				sum += idx1 * idx2 * minCnt;
			}
		}
		return sum;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
