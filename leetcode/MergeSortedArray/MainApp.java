// Copyright (C) 2021 by iamslash

import java.util.*;

//     m: 3
//          i
// nums1: 1 2 3 0 0 0
//          j
//     n: 3
// nums2: 2 5 6
//        k

// brute force
// O(M+N) O(M+N)
class Solution {
	public void merge(int[] nums1, int m, int[] nums2, int n) {
		int[] rst = new int[m+n];
		for (int i = 0, j = 0, k = 0; i < m+n; ++i) {
			if (k == n || (j < m && nums1[j] <= nums2[k])) {
				rst[i] = nums1[j++];
			} else {
				rst[i] = nums2[k++];
			}
            // System.out.println(rst[i]);
		}
        // for (int i = 0; i < m+n; ++i) {
        //     System.out.printf("%d ", rst[i]);
        // }
        // System.out.println();
		System.arraycopy(rst, 0, nums1, 0, m+n);
	}
}

//     m: 3
//                  i
// nums1: 1 2 3 0 0 0
//            j
//     n: 3
// nums2: 2 5 6
//            j

// 0ms 100.00% 39.5MB 26.00%
// brute force
// O(M+N) O(1)
class Solution {
	public void merge(int[] nums1, int m, int[] nums2, int n) {
		int j = m-1, k = n-1;
		for (int i = m+n-1; i >= 0; --i) {
			if (k < 0) {
				break;
			}
			if (j >= 0 && nums1[j] > nums2[k]) {
				nums1[i] = nums1[j--];
			} else {
				nums1[i] = nums2[k--];
			}
		}
	}	
}

public class MainApp {
  public static void main(String[] args) {
  }
}
