// Copyright (C) 2021 by iamslash

import java.util.*;

//                i
// nums1:  55 30  5  4 2
// nums2: 100 20 10 10 5
//                       j
// 

// 2ms 100.00% 51.7MB 80.00%
// two pointers
// O(N) O(1)
class Solution {
	public int maxDistance(int[] nums1, int[] nums2) {
		int i = 0, j = 0, ans = 0;
		int n = nums1.length, m = nums2.length;
		while (i < n && j < m) {
			if (nums1[i] > nums2[j]) {
				i++;
			} else {
				ans = Math.max(ans, j - i);
				j++;
			}
		}
		return ans;
	}
}

public class MainApp {
  public static void main(String[] args) {
  }
}
